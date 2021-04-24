/**
 * Author: Bao Wenjie
 * Date: 2021/4/6
 * Link: http://codeup.cn/problem.php?cid=100000622&pid=2
 */

#include <cstdio>
#include <vector>
#include <algorithm>
#define scanf scanf_s
#define printf printf_s

using namespace::std;
const int maxn = 105;
const int inf = 99999;

int parent[maxn] = { 0 };
int nums[maxn] = { 1 };

struct edge
{
	int x;
	int y;
	int w;
}Edge;

int Find(int x)
{
	int a = x;
	while(parent[x] != x)
	{
		x = parent[x];
	}
	while(parent[a] != x)
	{
		int tmp = parent[a];
		parent[a] = x;
		a = tmp;
	}
	return x;
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	parent[a] = b;
	nums[b] += nums[a];
}

bool cmp(struct edge& a, struct edge& b)
{
	return a.w <= b.w;
}

int main()
{
	int N, M;
	while (true)
	{
		for (int i = 0; i < maxn; i++)
		{
			nums[i] = 1;
			parent[i] = i;
		}
		scanf("%d%d", &N, &M);
		vector<struct edge>vec(N, Edge);
		int x, y, w;
		for (int i = 0; i < N; i++)
		{
			scanf("%d%d%d", &x, &y, &w);
			vec[i].x = x - 1;
			vec[i].y = y - 1;
			vec[i].w = w;
		}
		sort(vec.begin(), vec.begin() + N, cmp);
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			struct edge& tmp = vec[i];
			if (Find(tmp.x) != Find(tmp.y))
			{
				count += tmp.w;
				Union(tmp.x, tmp.y);
			}
			if (nums[Find(tmp.x)] == M)
			{
				break;
			}
		}
		if (nums[Find(0)] == M)
			printf("%d\n", count);
		else
			printf("?\n");
	}
}