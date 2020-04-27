#include <easyx.h>
#include <math.h>
#include <stdio.h>
#define PI 3.1415926

int main()
{
	int size = 500;
	int centerX = size/2;
	int centerY = size/2;
	int radius = centerX - 50;
	double angle = 0;
	int x = centerX;
	int y = centerY - radius;
	double sum_time = 160;
	initgraph(size, size);
	moveto(x, y);
	setlinecolor(WHITE);
	for (int i(0); i<int(sum_time); i++)
	{
		angle += 1 / sum_time * 2 * PI;
		x = (int)(centerX + sin(angle) * radius);
		y = (int)(centerY - cos(angle) * radius);
		lineto(x, y);
		Sleep(200);
	}
	Sleep(100000);
}
