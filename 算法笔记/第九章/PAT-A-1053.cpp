/**
 * Author: Bao Wenjie
 * Date: 2021/3/9
 * Link: https://pintia.cn/problem-sets/994805342720868352/problems/994805424153280512
 */

#include <cstdio>
#include <vector>
#include <algorithm>
#define scanf scanf_s
#define printf printf_s

using namespace ::std;
const int maxn = 110;

struct node
{
	int weight;
	vector<int> childs;
}Node[maxn];

int N, M, S;

int path[110];

void DFS(int index, int target, int p)
{
	struct node& now_node = Node[index];
	target -= now_node.weight;
	if(target == 0)
	{
		if(now_node.childs.empty())
		{
			for (int i = 0; i < p; i++)
				printf("%d ", path[i]);
			printf("%d\n", now_node.weight);
			return;
		}
	}
	else if(target < 0)
	{
		return;
	}
	else
	{
		for(int i = 0; i < now_node.childs.size(); i++)
		{
			path[p] = now_node.weight;
			DFS(now_node.childs[i], target, p + 1);
		}
	}
}

bool cmp(int a, int b)
{
	return Node[a].weight > Node[b].weight;
}

int main()
{
	scanf("%d%d%d", &N, &M, &S);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &(Node[i].weight));
	}
	for(int i = 0; i < M; i++)
	{
		int id = 0, n = 0;
		scanf("%d%d", &id, &n);
		vector<int>& tmp = Node[id].childs;
		int k = 0;
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &k);
			tmp.push_back(k);
		}
		sort(tmp.begin(), tmp.end(), cmp);
	}
	DFS(0, S, 0);
	return 0;
}