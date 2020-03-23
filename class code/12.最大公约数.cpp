#include <stdio.h>

int gcdRecursion(int a, int b)
{
	if (0 == b)
		return a;
	return gcdRecursion(b, a % b);
}

int gcdLoop(int a, int b)
{
	int temp;
	while (b)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
int main()
{
	int a, b;
	scanf_s("%d%d", &a, &b);
	printf_s("Recursion:%d\n", gcdRecursion(a, b));
	printf_s("Loop:%d\n", gcdLoop(a, b));

	return 0;
}