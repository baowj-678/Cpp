/**
 * @author: Bao Wenjie
 * @date: 2021/5/18
 * @link: https://www.luogu.com.cn/problem/P1434
 */

#include <cstdio>
#include <algorithm>
#define MAXN 105
#define scanf scanf_s

int g[MAXN][MAXN] = { 0 };
int dp[MAXN][MAXN] = { 0 };

int dfs(int x, int y, int r, int c)
{
	if(x >= 1 && g[x-1][y] > g[x][y])
	{
		if (dp[x - 1][y] == 0)
			dfs(x-1,y, r, c);
		dp[x][y] = std::max(dp[x][y], dp[x - 1][y] + 1);
	}
	if (y >= 1 && g[x][y-1] > g[x][y])
	{
		if (dp[x][y - 1] == 0)
			dfs(x, y - 1, r, c);
		dp[x][y] = std::max(dp[x][y], dp[x][y - 1] + 1);
	}
	if (x < r - 1 && g[x + 1][y] > g[x][y])
	{
		if (dp[x + 1][y] == 0)
			dfs(x + 1, y, r, c);
		dp[x][y] = std::max(dp[x][y], dp[x + 1][y] + 1);
	}
	if (y < c - 1 && g[x][y + 1] > g[x][y])
	{
		if (dp[x][y + 1] == 0)
			dfs(x, y + 1, r, c);
		dp[x][y] = std::max(dp[x][y], dp[x][y + 1] + 1);
	}
	return dp[x][y];
}

int main()
{
	int R, C;
	scanf("%d%d", &R, &C);
	for(int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			scanf("%d", &g[i][j]);
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			dfs(i, j, R, C);
	int max_ = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			max_ = std::max(max_, dp[i][j]);
	printf("%d\n", max_ + 1);
	return 0;
}