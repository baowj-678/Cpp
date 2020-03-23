#include<stdio.h>

using namespace::std;

void PrintDigit(int n)
{
	if (n <= 9 && n >= 0)
		printf_s("%d", n);
}

void print(int n)
{
	if (n > 0)
	{
		int last = n % 10;
		n /= 10;
		print(n);
		PrintDigit(last);
	}
	else if (n < 0)
	{
		printf_s("-");
		print(-n);
	}
	else
	{
		printf_s("%d", n);
	}
}
int main()
{
	int n;
	scanf_s("%d", &n);
	while (n)
	{
		print(n);
		printf_s("\n");
		scanf_s("%d", &n);
	}
	return 0;
}