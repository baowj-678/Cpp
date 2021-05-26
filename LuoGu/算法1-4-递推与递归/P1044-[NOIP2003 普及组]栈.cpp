/**
 * @author: Bao Wenjie
 * @date: 2021/5/26
 * @link: https://www.luogu.com.cn/problem/P1044
 */

#include <cstdio>
#define MAXN 100
#define scanf scanf_s

long long dp[MAXN];

long long find(int n)
{
	if (dp[n] != 0)
		return dp[n];
	else
	{
		long long tmp = 0;
		for(int i = 1; i <= n; i++)
		{
			tmp += (find(i - 1) * find(n - i));
		}
		dp[n] = tmp;
		return tmp;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	dp[0] = dp[1] = 1;
	find(n);
	printf("%d\n", dp[n]);
	return 0;
}