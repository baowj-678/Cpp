/**
* @Title: Dijkstra算法
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/8/21
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define	INF	999999
using namespace::std;
struct Edge
{
	int from;
	int to;
	int value;
};
typedef Edge* pEdge;
struct Match
{
	int vertex;
	int value;
};


int* Dijkstra(vector<vector<pEdge>> Graph, int n, int s);
bool cmp(Match*& a, Match*& b);
int main()
{
	// 输入
	int n, m, s;
	cout << "请输入结点个数：" << endl;
	cin >> n;
	cout << "请输入边个数：" << endl;
	cin >> m;
	cout << "请输入源点序号（从0开始）：" << endl;
	cin >> s;
	vector<vector<pEdge>> Graph(m);
	int u, v, value;
	for (int i(0); i < m; i++)
	{
		cin >> u;
		cin >> v;
		cin >> value;
		pEdge tmp = new Edge;
		tmp->from = u;
		tmp->to = v;
		tmp->value = value;
		Graph[u].push_back(tmp);
	}
	// 计算
	int* T = Dijkstra(Graph, n, s);
	// 输出
	for (int i(0); i < n; i++)
		cout << T[i] << " ";
	return 0;
}

/**
* @Graph: 图
* @n: 结点个数
* @s: 源点
*/
int* Dijkstra(vector<vector<pEdge>> Graph, int n, int s)
{
	// 初始化
	Match* S = new Match[n];
	vector<Match*> heap;
	for (int i(0); i < n; i++)
	{
		S[i].vertex = i;
		S[i].value = INF;
	}
	S[s].value = 0;
	heap.push_back(S + s);
	int* T = new int[n];
	make_heap(heap.begin(), heap.end(), cmp);
	// 
	Match* tmp;
	for (int i(0); heap.size() > 0; i++)
	{
		tmp = heap[0];
		T[tmp->vertex] = tmp->value;
		pop_heap(heap.begin(), heap.end(), cmp);
		heap.pop_back();
		int u = tmp->vertex;
		int value = tmp->value;
		if (value == INF)
			break;
		int v;
		vector<pEdge>::iterator itor = Graph[u].begin();
		while (itor != Graph[u].end())
		{
			v = (*itor)->to;
			if ((*itor)->value == INF)
			{
				itor++;
				continue;
			}
			int value_ = value + (*itor)->value;
			if (S[v].value > value_)
			{
				S[v].value = value_;
				heap.push_back(S + v);
				push_heap(heap.begin(), heap.end(), cmp);
			}
			itor++;
		}
	}
	return T;
}

/**
* 最小堆比较函数
*/
bool cmp(Match*& a, Match*& b)
{
	return a->value > b->value;
}