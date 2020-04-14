#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <queue>
#include <Windows.h>
#define     TINY_BLOCK_SIZE     10240
#define     BUFF                128
#define     THREAD_COUNT        5
#define     SINGLE_THREAD_COUNT 3
using namespace std;

//任务信息
typedef struct TASK_INFO
{
    string src;
    string des;
    unsigned long size;
}Info;
typedef Info* pInfo;

//文件块信息
typedef struct THREAD_BLOCK
{
    FILE* inf;
    FILE* outf;
    size_t    start_position;//文件的写入起始位置
    size_t    block_size; //文件写入的终止位置[first ,last)开区间
    int fileID;
    queue<int> openedFiles;
    CRITICAL_SECTION* mutex;
}ThreadBlock;
typedef ThreadBlock* pThreadBlock;

LPCWSTR stringToLPCWSTR(std::string orig)
{
    size_t origsize = orig.length() + 1;
    const size_t newsize = 100;
    size_t convertedChars = 0;
    wchar_t* wcstring = (wchar_t*)malloc(sizeof(wchar_t) * (orig.length() - 1));
    mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);

    return wcstring;
}

//文件块拷贝函数
DWORD WINAPI TinyFileBlockCopy(LPVOID pThreadBlockVOID)
{
    pThreadBlock pTempThreadBlock = (pThreadBlock)pThreadBlockVOID;
    char buf[BUFF + 1] = "";
    FILE* fin = pTempThreadBlock->inf;
    FILE* fout = pTempThreadBlock->outf;

    fseek(fin, pTempThreadBlock->start_position, SEEK_SET);
    int n = pTempThreadBlock->block_size / BUFF;
    n += (pTempThreadBlock->block_size - n * BUFF) ? 1 : 0;
    for (int i(0); i < n; i++)
    {
        if (i == n - 1)
        {
            int size = pTempThreadBlock->block_size - (n - 1) * BUFF;
            fread(buf, sizeof(char), size, fin);
            fwrite(buf, sizeof(char), size, fout);

        }
        else
        {
            fread(buf, sizeof(char), BUFF, fin);
            fwrite(buf, sizeof(char), BUFF, fout);
        }
    }
    cout << "hgasfd";
    EnterCriticalSection(pTempThreadBlock->mutex);
    pTempThreadBlock->openedFiles.push(pTempThreadBlock->fileID);
    LeaveCriticalSection(pTempThreadBlock->mutex);
    delete pTempThreadBlock;
    return 0;
}

//单个文件拷贝函数
DWORD WINAPI SingleFileCopy(LPVOID taskInfo)
{
    pInfo tempInfo = (pInfo)taskInfo;
    int n = tempInfo->size / TINY_BLOCK_SIZE;
    n += (tempInfo->size - TINY_BLOCK_SIZE * n) ? 1 : 0;
    int ThreadCount;
    if (n <= SINGLE_THREAD_COUNT * 5)
        ThreadCount = 1;
    else if (n <= 10 * SINGLE_THREAD_COUNT)
        ThreadCount = 2;
    else
        ThreadCount = 3;
    queue<int> openFileEmpty;
    FILE** inFiles = new FILE* [ThreadCount];
    FILE** outFiles = new FILE* [ThreadCount];
    for (int i(0); i < ThreadCount; i++)
    {
        fopen_s(&inFiles[i], tempInfo->src.c_str(), "r");
        int n = fopen_s(&outFiles[i], tempInfo->des.c_str(), "w+");
        if (i == 0)
        {
            _chsize(_fileno(outFiles[0]), tempInfo->size);
        }
        openFileEmpty.push(i);
    }
    CRITICAL_SECTION ThreadBlockMutex;
    HANDLE empty;
    InitializeCriticalSection(&ThreadBlockMutex);
    empty = CreateSemaphore(NULL, SINGLE_THREAD_COUNT, SINGLE_THREAD_COUNT, NULL);
    DWORD ThreadID;
    for (int i(0); i < n; i++)
    {
        //prepare thread block
        WaitForSingleObject(empty, INFINITE);
        pThreadBlock threadBlock = new ThreadBlock;
        EnterCriticalSection(&ThreadBlockMutex);
        threadBlock->fileID = openFileEmpty.front();
        openFileEmpty.pop();
        threadBlock->openedFiles = openFileEmpty;
        LeaveCriticalSection(&ThreadBlockMutex);
        threadBlock->inf = inFiles[threadBlock->fileID];
        threadBlock->outf= outFiles[threadBlock->fileID];
        threadBlock->mutex = &ThreadBlockMutex;
        threadBlock->start_position = i * TINY_BLOCK_SIZE;
        if (i == n - 1)
            threadBlock->block_size = tempInfo->size - (n - 1) * TINY_BLOCK_SIZE;
        else
            threadBlock->block_size = TINY_BLOCK_SIZE;
        CreateThread(NULL, 0, TinyFileBlockCopy, LPVOID(tempInfo), 0, &ThreadID);
        ReleaseSemaphore(empty, 1, NULL);
    }
    delete tempInfo;
    Sleep(10000);
    return 0;
}



//多文件分配函数
void AllocFiles(vector<pInfo> pTaskInfoVector)
{
    DWORD ThreadID;
    CRITICAL_SECTION  AllocMutex;
    HANDLE FilesEmpty = CreateSemaphore(NULL, THREAD_COUNT, THREAD_COUNT, NULL);
    InitializeCriticalSection(&AllocMutex);
    while (pTaskInfoVector.empty() == false)
    {
        WaitForSingleObject(FilesEmpty, INFINITE);
        EnterCriticalSection(&AllocMutex);
        pInfo tempInfo = pTaskInfoVector.back();
        pTaskInfoVector.pop_back();
        CreateThread(NULL, 0, SingleFileCopy, LPVOID(tempInfo), 0, &ThreadID);
        LeaveCriticalSection(&AllocMutex);
        ReleaseSemaphore(FilesEmpty, 1, NULL);
    }
    Sleep(10000);
     
}


//获取目录下所有文件
//文件夹不加//
void GetSrcFileName(string path, string relatedPath, vector<pInfo>& taskInfo, vector<string>& folderNames)
{
    folderNames.push_back(relatedPath);
    long hFile = 0;
    struct _finddata_t fileInfo;
    string pathName, exdName;
    if ((hFile = _findfirst(pathName.assign(path).append(relatedPath).append("\\*").c_str(), &fileInfo)) == -1) 
    {
        return;
    }

    do
    {
        // 是文件夹
        if (fileInfo.attrib & _A_SUBDIR)
        {
            if (strcmp(fileInfo.name,".") == 0 || strcmp(fileInfo.name, "..") == 0)
                continue;
            string subRelatedPath = relatedPath + "\\" + fileInfo.name;
            GetSrcFileName(path, subRelatedPath, taskInfo, folderNames);
        }
        else
        {
            string subRelatedPath = relatedPath + "\\" + fileInfo.name;
            pInfo tempInfo = new Info;
            tempInfo->src = subRelatedPath;
            tempInfo->size = fileInfo.size;
            taskInfo.push_back(tempInfo);

        }
    } while (_findnext(hFile, &fileInfo) == 0);
    _findclose(hFile);
}

//创建文件夹
void CreateFold(vector<string> folderPaths, string desPath)
{
    string folderPath;
    for (int i(0); i < folderPaths.size(); i++)
    {
        folderPath = desPath + folderPaths[i];
        if (GetFileAttributesA(folderPath.c_str()) != FILE_ATTRIBUTE_DIRECTORY) {
            CreateDirectory(stringToLPCWSTR(folderPath), NULL);
        }
    }
}

void MergePath(vector<pInfo>taskInfos, string src, string des)
{
    for (int i(0); i < taskInfos.size(); i++)
    {
        taskInfos[i]->des = des + taskInfos[i]->src;
        taskInfos[i]->src = src + taskInfos[i]->src;
    }
}

int main()
{
    string src = "E:\\a";
    string des = "E:\\we";
    string relatedPath = "";
    vector<pInfo> taskInfos;
    vector<string>folderNames;
    GetSrcFileName(src, relatedPath, taskInfos, folderNames);
    MergePath(taskInfos, src, des);
    CreateFold(folderNames, des);
    AllocFiles(taskInfos);
}