#include <stdio.h>

using namespace::std;

int PizzaCut(int n)
{
	if (n == 0)
		return 1;
	return (PizzaCut(n - 1) + n);
}

int main()
{
	int n;
	scanf_s("%d", &n);
	printf_s("%d\n", PizzaCut(n));
	return 0;
}


/*
分析：第n刀最多能使一块披萨新增加n块
第0刀时，有1块
*/
