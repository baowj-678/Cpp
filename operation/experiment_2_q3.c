#include <Windows.h>
#include <stdio.h>




DWORD WINAPI A(LPVOID lpParameter)
{
	int n = 1000;
	int i = 1;
	for (i; i <= n; i++)
	{
		Sleep(500);
		printf("%d  ", i);
	}
	return 0;
}

DWORD WINAPI B(LPVOID lpParameter)
{
	int i = 1000;
	for (i; i > 0; i--)
	{
		Sleep(500);
		printf("%d  ", i);
	}
	return 0;
}
int main()
{
	HANDLE hThread[2];
	DWORD ThreadID;
	hThread[0] = CreateThread(NULL, 0, A, (LPVOID)(0), 0, &ThreadID);
	hThread[1] = CreateThread(NULL, 0, B, (LPVOID)(0), 0, &ThreadID);
	WaitForMultipleObjects(2, hThread, TRUE, INFINITE);
	return 0;
}