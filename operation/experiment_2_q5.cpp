#include <stdio.h>
#include <Windows.h>
#include <easyx.h>
#include <math.h>
#define PI 3.1415926
CRITICAL_SECTION mutex;

DWORD WINAPI drawSquare(LPVOID lpParameter)
{
	int size = 500;
	int sleepTime = 200;
	int radius = size - 100;
	int x = 50;
	int lastX = 50;
	int y = 50;
	int lastY = 50;
	int i;
	double sum_time = 40;
	setlinecolor(WHITE);

	for (i = 0; i<(int)(sum_time); i++)
	{
		EnterCriticalSection(&mutex);
		moveto(lastX, lastY);
		x += radius / sum_time;
		lineto(x, y);
		lastX = x;
		lastY = y;
		LeaveCriticalSection(&mutex);
		Sleep(sleepTime);
	}
	for (i = 0; i<(int)(sum_time); i++)
	{
		EnterCriticalSection(&mutex);
		moveto(lastX, lastY);
		y += radius / sum_time;
		lineto(x, y);
		lastX = x;
		lastY = y;
		LeaveCriticalSection(&mutex);
		Sleep(sleepTime);
	}
	for (i = 0; i<(int)(sum_time); i++)
	{
		EnterCriticalSection(&mutex);
		moveto(lastX, lastY);
		x -= radius / sum_time;
		lineto(x, y);
		lastX = x;
		lastY = y;
		LeaveCriticalSection(&mutex);
		Sleep(sleepTime);
	}
	for (i = 0; i<(int)(sum_time); i++)
	{
		EnterCriticalSection(&mutex);
		moveto(lastX, lastY);
		y -= radius / sum_time;
		lineto(x, y);
		lastX = x;
		lastY = y;
		LeaveCriticalSection(&mutex);
		Sleep(sleepTime);
	}
	Sleep(100000);
	return NULL;
}

DWORD WINAPI drawCircle(LPVOID lpParameter)
{
	int size = 500;
	int centerX = size / 2;
	int centerY = size / 2;
	int radius = centerX - 50;
	double angle = 0;
	int x = centerX + 500;
	int lastX = x;
	int y = centerY - radius;
	int lastY = y;
	int i;
	double sum_time = 160;
	setlinecolor(WHITE);

	for (i = 0; i<(int)(sum_time); i++)
	{
		EnterCriticalSection(&mutex);
		moveto(lastX, lastY);
		angle += 1 / sum_time * 2 * PI;
		x = 500 + (int)(centerX + sin(angle) * radius);
		y = (int)(centerY - cos(angle) * radius);
		lastX = x;
		lastY = y;
		lineto(x, y);
		LeaveCriticalSection(&mutex);
		Sleep(200);
	}
	Sleep(100000);
	return NULL;
}
int main()
{
	initgraph(1000, 500, NULL);
	InitializeCriticalSection(&mutex);
	HANDLE hThread[2];
	DWORD ThreadID;
	hThread[0] = CreateThread(NULL, 0, drawCircle, (LPVOID)(0), 0, &ThreadID);
	hThread[1] = CreateThread(NULL, 0, drawSquare, (LPVOID)(0), 0, &ThreadID);
	WaitForMultipleObjects(2, hThread, TRUE, INFINITE);
	return 0;
}