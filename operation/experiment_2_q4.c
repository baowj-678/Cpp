#include <Windows.h>
#include <stdio.h>

int buffer[10];
int i = 0;
CRITICAL_SECTION  mutex;
HANDLE empty;
HANDLE full;

DWORD WINAPI producer(LPVOID lpParameter)
{
	int j = 0;
	for (j; j < 10; j++)
	{
		WaitForSingleObject(empty, INFINITE);
		EnterCriticalSection(&mutex);
		int id = (int)lpParameter;
		buffer[i] = id;
		printf("producer-%d in; i=%d\n", id, ++i);
		Sleep(500);
		LeaveCriticalSection(&mutex);
		ReleaseSemaphore(full, 1, NULL);
	}
	return 0;
}

DWORD WINAPI consumer(LPVOID lpParameter)
{
	int j = 0;
	for (j; j < 10; j++)
	{
		WaitForSingleObject(full, INFINITE);
		EnterCriticalSection(&mutex);
		int id = (int)lpParameter;
		int n = buffer[i - 1] * 2;
		printf("consumer-%d in; i=%d\n", id, --i);
		Sleep(500);
		LeaveCriticalSection(&mutex);
		ReleaseSemaphore(empty, 1, NULL);
	}
	return 0;
}

int main()
{
	HANDLE hThread[10];
	DWORD ThreadID;
	InitializeCriticalSection(&mutex);
	empty = CreateSemaphore(NULL, 10, 10, NULL);
	full = CreateSemaphore(NULL, 0, 10, NULL);
	int i = 0;
	for (i; i < 5; i++)
	{
		hThread[i] = CreateThread(NULL, 0, producer, (LPVOID)(i), 0, &ThreadID);
		hThread[i + 5] = CreateThread(NULL, 0, consumer, (LPVOID)(i + 5), 0, &ThreadID);
	}
	WaitForMultipleObjects(10, hThread, TRUE, INFINITE);
	return 0;
}