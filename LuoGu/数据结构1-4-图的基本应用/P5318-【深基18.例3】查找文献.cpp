/**
 * @author: Bao Wenjie
 * @date: 2021/6/21
 * @link: https://www.luogu.com.cn/problem/P5318
 */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 1000050
#define scanf scanf_s

std::vector<int> G[MAXN];
bool isVisited[MAXN];
int dfs_ans[MAXN];
int bfs_ans[MAXN];
int dfs_i = 0;
int bfs_i = 0;

bool cmp(int x, int y)
{
	return x < y;
}

void dfs(int i)
{
	if (isVisited[i])
		return;
	dfs_ans[dfs_i++] = i;
	isVisited[i] = true;
	for(int x : G[i])
	{
		dfs(x);
	}
}

void bfs(int i)
{
	std::queue<int> Q;
	Q.push(i);
	while(!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		if(isVisited[x])
			continue;
		isVisited[x] = true;
		bfs_ans[bfs_i++] = x;
		for(int tmp:G[x])
		{
			Q.push(tmp);
		}
	}
}

int main()
{
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
	}
	for(int i = 1; i <= n; i++)
	{
		std::sort(G[i].begin(), G[i].end(), cmp);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
		isVisited[i] = false;
	bfs(1);
	for (int i = 0; i < dfs_i; i++)
		printf("%d ", dfs_ans[i]);
	printf("\n");
	for (int i = 0; i < bfs_i; i++)
		printf("%d ", bfs_ans[i]);
	printf("\n");
}