/**
 * @author: Bao Wenjie
 * @date: 2021/5/18
 * @link: https://www.luogu.com.cn/problem/P4017
 */

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define MAXN 5005
#define scanf scanf_s

int not_begin[MAXN] = { 0 };
int not_end[MAXN] = { 0 };
int is_visited[MAXN] = { 0 };
int dp[MAXN] = { 0 };
std::vector<int> fathers[MAXN];

int dfs(int p)
{
	int sum = 0;
	for(int father: fathers[p])
	{
		if(is_visited[father] == 1)
		{
			sum = (sum + dp[father]) % 80112002;
		}
		else
		{
			sum = (sum + dfs(father)) % 80112002;
		}
	}
	is_visited[p] = 1;
	dp[p] = sum;
	return sum;
}

int main()
{
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		not_end[x] = 1;
		not_begin[y] = 1;
		fathers[y].push_back(x);
	}
	for(int i = 1; i <= n; i++)
	{
		if(not_begin[i] == 0)
		{
			dp[i] = is_visited[i] = 1;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(not_begin[i] == 1)
		{
			dfs(i);
		}
		if(not_end[i] == 0)
		{
			ans = (ans + dp[i]) % 80112002;
		}
	}
	printf("%d\n", ans);
}