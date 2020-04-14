#include <easyx.h>
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#define PI 3.1415926

int main()
{
	int size = 600;
	int centerX = size / 2;
	int centerY = size / 2;
	int radius = centerX - 50;
	int x = centerX - radius;
	int y = centerY - radius;
	double sum_time = 100;
	initgraph(600, 600, SHOWCONSOLE);
	setlinecolor(WHITE);
	moveto(x, y);
	for (int i(0); i<int(sum_time); i++)
	{
		x += 2 * radius / sum_time;
		printf("%d %d\n", x, y);
		lineto(x, y);
		Sleep(10);
	}
	for (int i(0); i<int(sum_time); i++)
	{
		y += 2 * radius / sum_time;
		printf("%d %d\n", x, y);
		lineto(x, y);
		Sleep(10);
	}
	for (int i(0); i<int(sum_time); i++)
	{
		x -= 2 * radius / sum_time;
		printf("%d %d\n", x, y);
		lineto(x, y);
		Sleep(10);
	}
	for (int i(0); i<int(sum_time); i++)
	{
		y -= 2 * radius / sum_time;
		printf("%d %d\n", x, y);
		lineto(x, y);
		Sleep(10);
	}
	Sleep(100000);
}