#pragma    comment(lib,"Pdh.lib")
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
#include <Pdh.h>
#include <string>
#include <pdhmsg.h>
#include <tchar.h>
#include <windows.h>
#include <iostream>
using namespace std;

int get_main()
{
    HQUERY m_hQuery;
    HCOUNTER hCounter;
    PDH_FMT_COUNTERVALUE* m_pDisplayValue;

    PDH_STATUS status = ERROR_SUCCESS;
    m_pDisplayValue = new PDH_FMT_COUNTERVALUE();
    status = PdhOpenQuery(NULL, 0, &m_hQuery);
    //if (ERROR_SUCCESS == status)
    //{
        status = PdhAddCounter(m_hQuery, _T("\\Processor Information(_Total)\\% Processor Utility"), 0, &hCounter);
        //WIN10以前的路径换成：\\Processor(_Total)\\% Processor Time
        if (ERROR_SUCCESS != status)
        {
            return status;
        }
    //}
    while (1)
    {
        PDH_STATUS status = ERROR_SUCCESS;
        DWORD dwCounterType = 0;
        PdhCollectQueryData(m_hQuery);
        status = PdhGetFormattedCounterValue(hCounter, PDH_FMT_DOUBLE, &dwCounterType, m_pDisplayValue);
        double dCpuLoad = *(double*)((char*)m_pDisplayValue + 8);
        printf("CPULoad:%f\n", dCpuLoad);
        Sleep(500);
    }
    return 0;
}


int getCPU()
{
    HQUERY query;
    PDH_STATUS status = PdhOpenQuery(NULL, NULL, &query);
    PDH_STATUS AvilableMemorystatus = PdhOpenQuery(NULL, NULL, &query);

    if (status != ERROR_SUCCESS)
        cout << "Open Query Error" << endl;

    HCOUNTER counter;

    //counter = (HCOUNTER*)GlobalAlloc(GPTR, sizeof(HCOUNTER));
    HCOUNTER cntProcessCPU, cntAvilableMemory;
    status = PdhAddCounter(query, TEXT("\\Processor Information(_Total)\\% Processor Utility"), NULL, &counter);

    PdhCollectQueryData(query);
    Sleep(1000);
    PdhCollectQueryData(query);

    PDH_FMT_COUNTERVALUE pdhValue;
    DWORD dwValue;

    status = PdhGetFormattedCounterValue(counter, PDH_FMT_DOUBLE, &dwValue, &pdhValue);
    if (status != ERROR_SUCCESS)
        cout << "Get Value Error" << endl;
    cout << "processCPU:" << pdhValue.doubleValue << endl;

    return 0;
}
//

/*
通过性能计数器获取某个进程的CPU使用率、内存使用量、磁盘读写速率
使用性能计数器中的Process实现
*/



int nCPU;
using std::string;
using namespace std;
int GetData()
{
    HQUERY query;
    double dbVal;
    long iVal;
    //PDH_STATUS status = PdhOpenQuery(NULL, NULL, &query);
    PDH_STATUS status = PdhOpenQuery(0, 0, &query);
    if (ERROR_SUCCESS != status)
    {
        MessageBox(NULL, TEXT("打开失败"), TEXT(""), MB_OK);
        return -1;

    }
    HCOUNTER cntProcessCPU, cntProcessMemory;
    HCOUNTER cntProcessDiskRead, cntProcessDiskWrite;
    status = PdhAddCounter(query, TEXT("\\Processor Information(_Total)\\% Processor Utility"), NULL, &cntProcessCPU);
    status = PdhAddCounter(query, TEXT("\\Process(_Total)\\Working Set - Private"), NULL, &cntProcessMemory);
    status = PdhAddCounter(query, TEXT("\\Process(_Total)\\IO Read Bytes/sec"), NULL, &cntProcessDiskRead);
    status = PdhAddCounter(query, TEXT("\\Process(_Total)\\IO Write Bytes/sec"), NULL, &cntProcessDiskWrite);

    if (ERROR_SUCCESS != status)
    {
        MessageBox(NULL, TEXT("添加失败"), TEXT(""), MB_OK);
        return -1;
    }

    status = PdhCollectQueryData(query);
    Sleep(1000);                 //这里要有延时不然结果相当不准确
    status = PdhCollectQueryData(query);
    if (ERROR_SUCCESS != status)
    {
        MessageBox(NULL, TEXT("数据请求失败"), TEXT(""), MB_OK);
        return -1;
    }

    PDH_FMT_COUNTERVALUE pdhValue;
    DWORD dwValue;

    status = PdhGetFormattedCounterValue(cntProcessCPU, PDH_FMT_DOUBLE, &dwValue, &pdhValue);
    if (ERROR_SUCCESS != status)
    {
        MessageBox(NULL, TEXT("得到数据失败"), TEXT(""), MB_OK);
        return -1;
    }
    else
    {
        dbVal = pdhValue.doubleValue;
        printf("Process-CPU：          %.3f%%          ", (dbVal));
    }

    status = PdhGetFormattedCounterValue(cntProcessMemory, PDH_FMT_DOUBLE, &dwValue, &pdhValue);
    if (ERROR_SUCCESS != status)
    {
        MessageBox(NULL, TEXT("得到数据失败"), TEXT(""), MB_OK);
        return -1;
    }
    else
    {
        dbVal = pdhValue.doubleValue;
        printf("Process-Memory：     %8dK        \n", (int)(dbVal / 1024));
    }

    status = PdhGetFormattedCounterValue(cntProcessDiskRead, PDH_FMT_DOUBLE, &dwValue, &pdhValue);
    if (ERROR_SUCCESS != status)
    {
        MessageBox(NULL, TEXT("得到数据失败"), TEXT(""), MB_OK);
        return -1;
    }
    else
    {
        dbVal = pdhValue.doubleValue;
        printf("Process-DiskRead：%8dK/s        ", (int)(dbVal / 1024));
    }

    status = PdhGetFormattedCounterValue(cntProcessDiskWrite, PDH_FMT_DOUBLE, &dwValue, &pdhValue);
    if (ERROR_SUCCESS != status)
    {
        MessageBox(NULL, TEXT("得到数据失败"), TEXT(""), MB_OK);
        return -1;
    }
    else
    {
        dbVal = pdhValue.doubleValue;
        printf("Process-DiskWrite：%8dK/s        \n*****************************************************************************\n", (int)(dbVal / 1024));
    }

    PdhRemoveCounter(cntProcessCPU);
    PdhRemoveCounter(cntProcessMemory);
    PdhRemoveCounter(cntProcessDiskRead);
    PdhRemoveCounter(cntProcessDiskWrite);
    PdhCloseQuery(query);
}


int main() {
    setlocale(LC_ALL, "chs");

    SYSTEM_INFO si;
    GetSystemInfo(&si);
    nCPU = si.dwNumberOfProcessors;
    printf("hello\n");
    while (1)
    {
        //getCPU();
        GetData();
        //get_main();
    }
    system("pause");
    return 0;
}
