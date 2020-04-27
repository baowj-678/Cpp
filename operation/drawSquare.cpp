#include <easyx.h>
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#define PI 3.1415926

int main()
{
	int size = 500;
	int sleepTime = 200;
	int radius = size - 100;
	int x = 50;
	int y = 50;
	double sum_time = 40;
	initgraph(size, size);
	setlinecolor(WHITE);
	moveto(x, y);

	for (int i(0); i<int(sum_time); i++)
	{
		x += radius / sum_time;
		lineto(x, y);
		Sleep(sleepTime);
	}
	for (int i(0); i<int(sum_time); i++)
	{
		y += radius / sum_time;
		lineto(x, y);
		Sleep(sleepTime);
	}
	for (int i(0); i<int(sum_time); i++)
	{
		x -= radius / sum_time;
		lineto(x, y);
		Sleep(sleepTime);
	}
	for (int i(0); i<int(sum_time); i++)
	{
		y -= radius / sum_time;
		lineto(x, y);
		Sleep(sleepTime);
	}
	Sleep(100000);
}