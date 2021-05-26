/**
 * @author: Bao Wenjie
 * @date: 2021/5/26
 * @link: https://www.luogu.com.cn/problem/P1028
 */
#include <cstdio>
#define MAXN 1005
#define scanf scanf_s

long long dp[MAXN];

int main()
{
	int n;
	scanf("%d", &n);
	dp[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		long long tmp = 1;
		for(int j = 1; j <= i/2; j++)
		{
			tmp += dp[j];
		}
		dp[i] = tmp;
	}
	printf("%d\n", dp[n]);
}