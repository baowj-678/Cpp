#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <atlstr.h>
//新建进程
//1:
//int system(const char* command);

//2:
//UINT WinExec(
//	LPCSTR lpCmdLine, // command line
//	UINT uCmdShow // window style
//);

//3:
//HINSTANCE ShellExecute(
//	HWND hwnd,
//	LPCTSTR lpVerb,
//	LPCTSTR lpFile,
//	LPCTSTR lpParameters,
//	LPCTSTR lpDirectory,
//	INT nShowCmd
//);

//4:
//BOOL CreateProcess
//(
//	LPCTSTR lpApplicationName, // 可执行程序名
//	LPTSTR lpCommandLine, //[可执行程序名]程序参数
//	LPSECURITY_ATTRIBUTES lpProcessAttributes，
//	LPSECURITY_ATTRIBUTES lpThreadAttributes,
//	BOOL bInheritHandles,
//	DWORD dwCreationFlags, //创建标志
//	LPVOID lpEnvironment,
//	LPCTSTR lpCurrentDirectory,
//	LPSTARTUPINFO lpStartupInfo,
//	LPPROCESS_INFORMATION lpProcessInformation
//);


//结束进程
//1:
//VOID ExitProcess(UINT uExitCode);

//2:
//TerminateProcess(
//	HANDLE hProcess,
//	UINT uExitCode);


int main()
{
	//system("D:\\Snake.exe");
	//WinExec("D:\\Snake.exe", SW_SHOWMAXIMIZED);
	//ShellExecute(NULL, "open", "D:\\Snake.exe", NULL, NULL, SW_SHOWNORMAL);

	CString str = _T("D:\\Snake.exe");
	LPWSTR commandLine = str.GetBuffer();
	PROCESS_INFORMATION pi;
	STARTUPINFO si = { sizeof(si) };
	CreateProcess(commandLine, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi);
	return 0;
}