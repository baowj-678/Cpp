/**
 * @author Bao Wenjie
 * @date 2021/4/27
 * @link https://www.luogu.com.cn/problem/P1469
 */

#include <cstdio>
#define scanf scanf_s
#define LL long long

using namespace ::std;
int main()
{
	int n;
	LL x, sum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%lld", &x);
		sum ^= x;
	}
	printf("%lld\n", sum);
}