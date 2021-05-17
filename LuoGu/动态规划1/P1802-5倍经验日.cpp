/**
 * @author: Bao Wenjie
 * @date: 2021/5/17
 * @link: https://www.luogu.com.cn/problem/P1802
 */

#include <cstdio>
#include <algorithm>
#define MAXN 1005
#define scanf scanf_s

using namespace::std;

long long dp[MAXN][MAXN];

int main()
{
	int n, x, lose, win, use;
	scanf("%d%d", &n, &x);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &lose, &win, &use);
		for(int j = 0; j <= x; j++)
		{
			if(j >= use)
				dp[i][j] = std::max(dp[i - 1][j - use] + win, dp[i - 1][j] + lose);
			else
				dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + lose);
		}
	}

	printf("%lld\n", dp[n][x]*5);
}