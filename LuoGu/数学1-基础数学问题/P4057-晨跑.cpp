/**
 * @author: Bao Wenjie
 * @date: 2021/7/1
 * @link: https://www.luogu.com.cn/problem/P4057
 */
#include <cstdio>
#define scanf scanf_s

long long gcd(long long a, long long b)
{
	while(b != 0)
	{
		long long tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int main()
{
	long long a, b, c, a_b, a_c, b_c, z;
	scanf("%lld%lld%lld", &a, &b, &c);
	if (a > b)
		a_b = gcd(a, b);
	else
		a_b = gcd(b, a);
	if (a > c)
		a_c = gcd(a, c);
	else
		a_c = gcd(c, a);
	if (b > c)
		b_c = gcd(b, c);
	else
		b_c = gcd(c, b);
	if (a_b > a_c)
		z = gcd(a_b, a_c);
	else
		z = gcd(a_c, a_b);
	printf("%lld", a * b * c / a_c / b_c/ a_b * z);
	
}