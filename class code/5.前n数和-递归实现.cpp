#include<stdio.h>

using namespace::std;

int Sum(int n)
{
	if (n == 1)
		return 1;
	return (Sum(n - 1) + n);
}

int main()
{
	int n;
	scanf_s("%d", &n);
	printf_s("%d", Sum(n));
	return 0;
}