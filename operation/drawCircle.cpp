#include <easyx.h>
#include <math.h>
#include <stdio.h>
#define PI 3.1415926

int main()
{
	int size = 600;
	int centerX = size/2;
	int centerY = size/2;
	int radius = centerX - 50;
	double angle = 0;
	int x = centerX;
	int y = centerY - radius;
	double sum_time = 360;
	initgraph(600, 600, SHOWCONSOLE);
	moveto(x, y);
	for (int i(0); i<int(sum_time); i++)
	{
		angle += 1 / sum_time * 2 * PI;
		x = (int)(centerX + sin(angle) * radius);
		y = (int)(centerY - cos(angle) * radius);
		printf("%d %d\n", x, y);
		setlinecolor(WHITE);
		lineto(x, y);
		Sleep(10);
	}
	Sleep(100000);
}
