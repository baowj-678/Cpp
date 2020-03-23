#include <stdio.h>

using namespace::std;

int Fibonacci(int n)
{
	int temp1 = 1, temp2 = 1, fib;
	if (1 == n)
		return 1;
	if (2 == n)
		return 1;
	while (--n >= 2)
	{
		fib = temp1 + temp2;
		temp1 = temp2;
		temp2 = fib;
	}
	return fib;
}

int main()
{
	int n;
	scanf_s("%d", &n);
	while (n)
	{
		printf_s("Fibonacci:%d\n", Fibonacci(n));
		scanf_s("%d", &n);

	}
	return 0;
}