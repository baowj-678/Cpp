/**
 * @author: Bao Wenjie
 * @date: 2021/6/22
 * @link: https://www.luogu.com.cn/problem/P1226
 */

#include <cstdio>
#define scanf scanf_s

int main()
{
	long long a, b, p;
	scanf("%lld%lld%lld", &a, &b, &p);
	printf("%lld^%lld mod %lld=", a, b, p);
	long long ans = 1;
	while(b > 0)
	{
		if (b & 0b1 == 1)
		{
			ans = (ans * a) % p;
		}
		a = (a * a) % p;
		b >>= 1;
	}
	printf("%lld\n", ans % p);
}