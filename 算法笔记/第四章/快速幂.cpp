/**
* Author: Bao Wenjie
* Date: 2021/1/17
*/

#include <cstdio>

long long binaryPowRecursive(long long x, long long e, long long m)
{
	if (e == 0)
		return 1;
	if (e == 1)
		return x % m;
	long long tmp = binaryPowRecursive(x, e / 2, m);
	if (e % 2 == 1)
		return (tmp * tmp * x) % m;
	else
		return (tmp * tmp) % m;
}

long long binaryPowLoop(long long x, long long e, long long m)
{
	long long ans = 1;
	while (e > 0)
	{
		if(e & 1)
			ans = ans * x % m;
		x = x * x % m;
		e >>= 1;
	}
	return ans;
}

int main()
{
	printf("%d", binaryPowLoop(2, 8, 10));
}