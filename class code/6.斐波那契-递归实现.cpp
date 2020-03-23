#include <stdio.h>

using namespace::std;

int Fibonacci(int n)
{
	if (1 == n)
		return 1;
	if (2 == n)
		return 1;
	return (Fibonacci(n - 1) + Fibonacci(n - 2));
}

int main()
{
	int n;
	scanf_s("%d", &n);
	while (n)
	{
		printf_s("%d\n", Fibonacci(n));
		scanf_s("%d", &n);
	}
}