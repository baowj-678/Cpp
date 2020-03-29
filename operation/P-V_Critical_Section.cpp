#include <iostream>
#include <Windows.h>

/*
临界区机制(CRITICAL_SECTION)

function:
InitializeCriticalSection();
DeleteCriticalSection();
EnterCriticalSection();
LeaveCriticalSection();
*/
using namespace::std;
int nSum = 0;
int NUMBER = 80000;
HANDLE hThread[3];
CRITICAL_SECTION cs;


DWORD WINAPI Accumulate(LPVOID lpaaram)
{
	for (int i(0); i < NUMBER; i++)
	{
		EnterCriticalSection(&cs);
		int iCopy = nSum;
		nSum = iCopy + 1;
		LeaveCriticalSection(&cs);
	}
	return 0;
}

//int main()
//{
//	InitializeCriticalSection(&cs);
//	hThread[0] = CreateThread(NULL, 0, Accumulate, NULL, 0, NULL);
//	hThread[1] = CreateThread(NULL, 0, Accumulate, NULL, 0, NULL);
//	hThread[2] = CreateThread(NULL, 0, Accumulate, NULL, 0, NULL);
//	WaitForMultipleObjects(3, hThread, TRUE, INFINITE);
//	cout << nSum << endl;
//	return 0;
//}
