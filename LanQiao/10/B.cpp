/**
 * Author: Bao Wenjie
 * Date: 2021/3/18
 * Description: ¿∂«≈±≠µ⁄ ÆΩÏBÃ‚ 
 */

#include <cstdio>

int main()
{
	long long a = 1, b = 1, c = 1, d;
	for(int i = 0; i < 20190324 - 3; i++)
	{
		d = (a + b + c) % 100000;
		a = b;
		b = c;
		c = d;
	}
	printf("%lld\n", d);
	return 0;
}
