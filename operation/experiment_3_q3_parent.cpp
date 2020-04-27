#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <atlstr.h>

using namespace std;


int main()
{
	HANDLE hParentRead, hParentWrite, hChildRead, hChildWrite; //创建4个句柄

	STARTUPINFO si = { 0 };							//启动信息结构体
	si.cb = sizeof(si);
	PROCESS_INFORMATION pi = { 0 };                 //进程信息结构体

	SECURITY_ATTRIBUTES sa = { 0 };				   //安全属性描述符		
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = TRUE;                      //设置句柄可继承

	//创建管道1. 父进程读 -> 子进程写
	CreatePipe(&hParentRead, &hChildWrite, &sa, 0);

	//创建管道2. 子进程读 -> 父进程写.
	CreatePipe(&hChildRead, &hParentWrite, &sa, 0);

	////这里将子进程写重定向到 stdout中. 子进程读取重定向到stdinput中
	si.hStdInput = hChildRead;
	si.hStdOutput = hChildWrite;


	CString str = _T("D:/cpp/cpp algorithm/operation/experiment_3_q3/son_.exe");
	LPWSTR commandLine = str.GetBuffer();
	CreateProcess(commandLine, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi);

	char buffer [10];
	for (int i = 1; i <= 100; i++)
	{
		_itoa_s(i, buffer, 10);
		WriteFile(hParentWrite, buffer, 10, NULL, 0);//使用writeFile操作管道,给son发送数据命令.
		Sleep(10);
	}
	Sleep(10000);
	return 0;
}