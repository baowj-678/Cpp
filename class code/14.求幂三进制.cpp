#include <stdio.h>

int powRecursion(int x, int n)
{
	if (0 == n)
		return 1;

	if (n % 3 == 0)
		return powRecursion(x * x * x, n / 3);
	else if (n % 3 == 1)
		return powRecursion(x * x * x, n / 3) * x;
	else
		return powRecursion(x * x * x, n / 3) * x * x;
}

int powLoop(int x, int n)
{
	int res = 1;
	while (n > 0)
	{
		if (n % 3 == 1)
			res *= x;
		if (n % 3 == 2)
			res *= x * x;
		x *= x * x;
		n /= 3;
	}
	return res;
}

int main()
{
	int x, n;
	printf_s("please input x:\n");
	scanf_s("%d", &x);
	printf("please input n\n");
	scanf_s("%d", &n);
	printf_s("powRecursion:\n%d\n", powRecursion(x, n));
	printf_s("powLoop:\n%d", powLoop(x, n));
}