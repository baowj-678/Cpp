/**
 * @author: Bao Wenjie
 * @date: 2021/5/20
 * @link: https://www.luogu.com.cn/problem/P2758
 */

#include <cstdio>
#include <algorithm>
#include <string>
#define MAXN 2005

#define scanf scanf_s
int dp[MAXN][MAXN] = { 0 };
char s1[MAXN];
char s2[MAXN];

int main()
{
	scanf("%s", s1 + 1, MAXN);
	scanf("%s", s2 + 1, MAXN);
	int n = strlen(s1 + 1), m = strlen(s2 + 1);
	for(int i = 0; i <= n; i++)
	{
		dp[i][0] = i;
	}
	for(int i = 0; i <= m; i++)
	{
		dp[0][i] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			int min_ = INT_MAX;
			if (s1[i] == s2[j])
				min_ = std::min(dp[i - 1][j - 1], min_);
			else
				min_ = std::min(dp[i - 1][j - 1] + 1, min_);
			min_ = std::min(min_, dp[i - 1][j] + 1);
			min_ = std::min(min_, dp[i][j - 1] + 1);
			dp[i][j] = min_;
		}
	}
	printf("%d\n", dp[n][m]);
	return 0;
}
