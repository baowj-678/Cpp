/**
* Description: 分数类
* Author: Bao Wenjie
* Date: 2021/1/19
*/

#include <cstdio>
#include "第五章/LCm.cpp"
#include <iostream>

/**
* 分数存储
*/
struct Fraction {
	int up, down;
};


/**
* 分数化简
*/
Fraction reduction(Fraction result)
{
	if (result.down < 0)
	{
		result.up = -result.up;
		result.down = -result.down;
	}
	if (result.up == 0)
		result.down = 1;
	else
	{
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}

/**
* 分数加法
*/
Fraction add(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

/**
* 分数减法
*/
Fraction subtract(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up * f2.down - f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

/**
* 分数乘法
*/
Fraction multi(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}

/**
* 分数除法
*/
Fraction divide(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up * f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);
}

/**
* 分数打印
*/
void showResult(Fraction f)
{
	f = reduction(f);
	if (f.down == 1)
		printf("%lld", f.up);
	else if (abs(f.up) > f.down)
		printf("%d %d/%d", f.up / f.down, abs(f.up) % f.down, f.down);
	else
	{
		printf("%d/%d", f.up, f.down);
	}
}