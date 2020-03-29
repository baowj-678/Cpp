#include <Windows.h>
#include <iostream>


//DWORD DrawCircle()
DWORD WINAPI printOne(LPVOID lpParameter)
{
	int n = (int)lpParameter;
	for (int i(0); i < n; i++)
	{
		Sleep(500);
		std::cout << 1 << std::endl;
	}
	return 0;
}

DWORD WINAPI printTwo(LPVOID lpParameter)
{
	int n = (int)lpParameter;
	for (int i(0); i < n; i++)
	{
		Sleep(500);
		std::cout << 2 << std::endl;
	}
	return 0;
}


int main()
{
	HANDLE hThread[2];
	DWORD ThreadID;
	hThread[0] = CreateThread(NULL, 0, printOne, LPVOID(10), 0, &ThreadID);
	hThread[1] = CreateThread(NULL, 0, printTwo, LPVOID(11), 0, &ThreadID);
	WaitForMultipleObjects(2, hThread, TRUE, INFINITE);
	return 0;
}


//HANDLE CreateThread(
//	LPSECURITY_ATTRIBUTES lpThreadAttributes,
//	DWORD dwStackSize,
//	LPTHREAD_ROUTINE ThreadFunction, //线程函数
//	LPVOID lpParameter //线程函数的参数 )

//线程函数的原型
//DWORD ThreadFunction(
//	LPVOID lpParameter //参数)