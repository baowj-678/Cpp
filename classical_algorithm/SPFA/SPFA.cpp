/**
* @Title: SPFA算法
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/8/21
* @IDE: Microsoft Visual Studio Community 2019 版本 16.7.2
*/

#include <iostream>
#include <queue>
#include<vector>
#define INF	9999999
using namespace::std;

/**
* 边的结构体
*/
struct Edge {
	int from;
	int to;
	int value;
};

typedef Edge* pEdge;
/**
* @n n个节点
* @Graph 邻接矩阵
* @s 起点
*/
int* SPFA(int n, vector<vector<pEdge>> Graph, int s);
int main()
{
	// 输入
	int n;
	cout << "请输入节点数:" << endl;
	cin >> n;
	int m;
	cout << "请输入边数:" << endl;
	cin >> m;
	int s;
	cout << "请输入源点编号（从0开始）:" << endl;
	cin >> s;
	int u, v, value;
	vector<vector<pEdge>> Graph(n);
	for (int i(0); i < m; i++)
	{
		pEdge tmp = new Edge;
		cin >> u >> v >> value;
		if (value == -1)
			value = INF;
		tmp->value = value;
		tmp->from = u;
		tmp->to = v;
		Graph[u].push_back(tmp);
	}
	// 计算
	int* ans = SPFA(n, Graph, s);
	// 输出
	for (int i(0); i < n; i++)
		cout << ans[i] << " ";
	return 0;
}

int* SPFA(int n, vector<vector<pEdge>> Graph, int s)
{
	// 初始化
	queue<int> Q;
	/**
	* 记录每个节点到s点距离
	*/
	int* d = new int[n];
	/**
	* 记录每个节点遍历次数
	*/
	int* count = new int[n];
	for (int i(0); i < n; i++)
	{
		count[i] = 0;
		if (i != s)
			d[i] = INF;
	}
	d[s] = 0;
	Q.push(s);
	// 计算
	while (Q.empty() == false)
	{
		int u = Q.front();
		Q.pop();
		vector<pEdge> Vs = Graph[u];
		vector<pEdge>::iterator itor = Vs.begin();
		while (itor != Vs.end())
		{
			if (d[u] == INF)
				break;
			else
			{
				int v = (*itor)->to;
				int value = (*itor)->value;
				if (value == INF)
					continue;
				else
					value += d[u];
				if (d[v] > value)
				{
					d[v] = value;
					count[v]++;
					if (count[v] > n)
						return NULL;
					Q.push(v);
				}
				itor++;
			}
		}
	}
	return d;
}