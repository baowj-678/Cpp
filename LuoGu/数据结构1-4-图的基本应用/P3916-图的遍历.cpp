/**
 * @author: Bao Wenjie
 * @date: 2021/6/21
 * @link: https://www.luogu.com.cn/problem/P3916
 */

#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 100050
#define scanf scanf_s

std::vector<int> G[MAXN];
int max_value[MAXN];
bool is_visited[MAXN];

void dfs(int i, int max_)
{
	if (is_visited[i])
	{
		return;
	}
	is_visited[i] = true;
	max_ = std::max(i,max_);
	for(int x:G[i])
	{
		dfs(x, max_);
	}
	max_value[i] = max_;
	return;
}

int main()
{
	int N, M, x, y;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; i++)
	{
		scanf("%d%d", &x, &y);
		G[y].push_back(x);
	}
	for(int i = N; i >= 1; i--)
	{
		dfs(i, i);
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", max_value[i]);
	printf("\n");
}