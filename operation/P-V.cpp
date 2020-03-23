#include <iostream>
#include <Windows.h>


using namespace::std;
int nSum = 0;
int NUMBER = 80000;
HANDLE hThread[3];
DWORD WINAPI Accumulate(LPVOID lpaaram)
{
	for (int i(0); i < NUMBER; i++)
	{
		int iCopy = nSum;
		nSum = iCopy + 1;
	}
	return 0;
}

int main()
{
	hThread[0] = CreateThread(NULL, 0, Accumulate, NULL, 0, NULL);
	hThread[1] = CreateThread(NULL, 0, Accumulate, NULL, 0, NULL);
	hThread[2] = CreateThread(NULL, 0, Accumulate, NULL, 0, NULL);
	WaitForMultipleObjects(3, hThread, TRUE, INFINITE);
	cout << nSum << endl;
	return 0;
}
