/**
* Topic: CSP-2018-12-CIDR合并
* Author: Bao Wenjie
* Email: bwj_678@qq.com
* Date: 2020/8/19
*/
#include <iostream>
#include <algorithm>
#define	MAX_EDGE	100010
#define	MAX_VETEX	50010
struct Edge {
	int v;
	int u;
	int t;
};
struct Edge edge[MAX_EDGE];
int vertex[MAX_VETEX];
using namespace::std;

// 运算符重载
bool operator < (struct Edge& a, struct Edge& b);
// 并查集
int find(int x, int vertex[]);
int main()
{
	// 读入数据
	int n, m, root;
	int v, u, t;
	scanf_s("%d%d%d", &n, &m, &root);
	for (int i(0); i < m; i++)
	{
		scanf_s("%d%d%d", &(edge[i].v), &(edge[i].u), &(edge[i].t));
	}
	// 初始化：给edge排序
	memset(vertex, 0, sizeof(int) * MAX_VETEX);
	sort(edge, edge + m);
	for (int i(0); i <= n; i++)
		vertex[i] = i;
	// kruskal算法
	int maxValue = 0;
	for (int i(0); i < m; i++)
	{
		if (find(edge[i].v, vertex) != find(edge[i].u, vertex))
		{
			if (maxValue < edge[i].t)
				maxValue = edge[i].t;
			vertex[find(edge[i].u, vertex)] = find(edge[i].v, vertex);
		}
	}
	printf_s("%d\n", maxValue);
}

/**
* 运算符重载
*/
bool operator < (struct Edge& a, struct Edge& b)
{
	return (a.t < b.t);
}

/**
* 并查集
*/
int find(int x, int vertex[])
{
	int tmp = x;
	while (tmp != vertex[tmp])
	{
		tmp = vertex[tmp];
	}
	// 压缩路径
	while (tmp != x)
	{
		int last = vertex[x];
		vertex[x] = tmp;
		x = last;
	}
	return tmp;
}