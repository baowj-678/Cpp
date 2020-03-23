#include <stdio.h>

int gcd(int x, int y)
{
	int tmp;
	while (y != 0)
	{
		tmp = y;
		y = x % y;
		x = tmp;
	}
	return x;

}

int main()
{
	printf("%d", gcd(12, 78));
}