/**
 * Author: Bao Wenjie
 * Date: 2021/3/14
 * Link: https://pintia.cn/problem-sets/994805342720868352/problems/994805392092020736
 */

#include <cstdio>
#include <vector>
#include <queue>
#define scanf scanf_s
#define printf printf_s
const int maxn = 1010;

using namespace ::std;

vector<int> G[maxn];
bool isVisited[maxn];

int BFS(int root, int L, int N)
{
	for (int i = 1; i <= N; i++)
		isVisited[i] = false;
	queue<int> Q;
	int level = 0, count = -1;
	Q.push(root);
	Q.push(-1);
	while(!Q.empty() && level <= L)
	{
		int node = Q.front();
		Q.pop();
		if(node == -1)
		{
			Q.push(-1);
			level++;
			continue;
		}
		if(isVisited[node])
			continue;
		count++;
		isVisited[node] = true;
		for(int x : G[node])
		{
			Q.push(x);
		}
	}
	return count;
}

int main()
{
	int N, L, M, K, tmp;
	scanf("%d%d", &N, &L);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &M);
		for(int j = 0; j < M; j++)
		{
			scanf("%d", &tmp);
			G[tmp].push_back(i);
		}
	}
	scanf("%d", &K);
	for(int i = 1; i < K; i++)
	{
		scanf("%d", &tmp);
		printf("%d\n", BFS(tmp, L, N));
	}
	scanf("%d", &tmp);
	printf("%d", BFS(tmp, L, N));
	return 0;
}