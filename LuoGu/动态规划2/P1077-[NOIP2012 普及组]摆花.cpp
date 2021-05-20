/**
 * @author: Bao Wenjie
 * @date: 2021/5/20
 * @link: https://www.luogu.com.cn/problem/P1077
 */

#include <cstdio>
#include <algorithm>
#define MAXN 105
#define MOD 1000007
#define scanf scanf_s

int dp[MAXN][MAXN] = { 0 };
int nums[MAXN] = { 0 };

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", nums + i);
	for(int i = 0; i <= n; i++)
	{
		dp[i][0] = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			int sum = 0;
			for(int k = 0; k <= nums[i] && j - k >= 0; k++)
			{
				sum = (sum + dp[i - 1][j - k]) % MOD;
			}
			dp[i][j] = sum;
		}
	}
	printf("%d\n", dp[n][m]);
	return 0;
}