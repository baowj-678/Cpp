/**
 * @author: Bao Wenjie
 * @date: 2021/6/9
 * @link: https://www.luogu.com.cn/problem/P1024
 */
#include <cstdio>
#include <cmath>
#define scanf scanf_s

double a, b, c, d;
double func(double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}

double newton(double left, double right)
{
	while(abs(right - left) > 1e-5)
	{
		double half = (left + right) / 2;
		if (func(left) * func(half) < 0)
			right = half;
		else
			left = half;
	}
	return (right + left) / 2;
}

int main()
{
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	double p1, p2;
	p1 = (-2 * b + sqrt(4 * b * b - 12 * a * c))/(6 * a);
	p2 = (-2 * b - sqrt(4 * b * b - 12 * a * c))/(6 * a);
	if(p1 < p2)
	{
		double tmp = p1;
		p1 = p2;
		p2 = tmp;
	}
	printf("%.2llf %.2llf %.2llf\n", newton(-100, p2), newton(p2, p1), newton(p1, 100));
	return 0;
}