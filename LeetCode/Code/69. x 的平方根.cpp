/*
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842...,
     由于返回类型是整数，小数部分将被舍去。
*/

#include <stdio.h>

int mySqrt(int x) 
{
	long s = 0;
	int small = 0, big = 46400;
	int mid = (small + big) / 2;
	while ((big - small) > 1)
	{
		if (mid * mid == x)
		{
			small = mid;
			break;
		}
		else if (mid * mid < x)
			small = mid;
		else
			big = mid;
		mid = (small + big) / 2;
	}
	return small;
}

int mySqrtLoop(int x)
{
	int i = 0;
	while (i * i < x)
		i++;
	return i - 1;
}
int main()
{
	int x;
	printf_s("please input x:\n");
	scanf_s("%d", &x);
	printf_s("%d", mySqrt(x));
}

//accepted