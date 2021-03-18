/**
 * Author: Bao Wenjie
 * Date: 2021/3/18
 * Description: ¿∂«≈±≠µ⁄ ÆΩÏEÃ‚ 
 */ 

#include <cstdio>

int main()
{
	long long n = 1001733993063167141;
	long long d = 212353;
	long long p = 891234941, q = 1123984201;
//	for(int i = 3; i * i < n; i += 2)
//	{
//		long long x = n / i;
//		if(i * x == n)
//		{
//			p = i;
//			q = x;
//			printf("%lld %lld\n", p, q);
//			break;
//		}
//	}
	long long tmp = n - p - q;
	long long d_ = tmp / d;
	printf("%lld\n", tmp);
	printf("%lld\n", d_ * d);
	return 0;
}
