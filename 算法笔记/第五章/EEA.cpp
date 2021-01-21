/**
* Description: 扩展欧几里得算法
* Author: Bao Wenjie
* Date: 2021/1/20
*/


int exGcd(int a, int b, int& x, int& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int g = exGcd(b, a % b, x, y);
	int tmp = x;
	x = y;
	y = tmp - a / b * y;
	return g;
}
