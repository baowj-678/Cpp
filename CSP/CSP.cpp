//#include <iostream>
//#define MAXN	1000+5
//
//using namespace::std;
//double ans[MAXN];
//
//int main()
//{
//	// 输入
//	int T;
//	int A, B, C, D;
//	double temp = 0;
//	scanf("%d", &T);
//	for (int i(0); i < T; i++)
//	{
//		scanf("%d%d%d%d", &A, &B, &C, &D);
//		temp = (A * D * D * D / 3.0 + (double)D * D / 2.0 + B * D) - (A * C * C * C / 3.0 + C * C / 2.0 + B * C);
//		if (temp < 0)
//			ans[i] = -temp;
//		else
//			ans[i] = temp;
//	}
//	// 输出
//	for (int i(0); i < T; i++)
//		printf("%.7f\n", ans[i]);
//}


//#include <iostream>
//
//using namespace::std;
//const long long MAX	= 1000000000 + 7;
//
//int main()
//{
//	long long n, ans = 0, base, a;
//	while (scanf_s("%lld", &n))
//	{
//		ans = 1;
//		base = 2;
//		a = n - 1;
//		while (a != 0)
//		{
//			if (a & 1 != 0)
//			{
//				ans = (ans * base) % MAX;
//			}
//			base = (base * base) % MAX;
//			a >>= 1;
//		}
//		printf("%lld\n", ans * n % MAX);
//	}
//}


//#include <iostream>
//using namespace::std;
//
//int main()
//{
//
//}


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
	cin >> n;//结点
	int m;
	cin >> m;//边
	int s = 0;
	int k;
	cin >> k;//传送门
	int u, v, value;
	vector<vector<pEdge>> Graph(n);
	for (int i(0); i < m; i++)
	{
		pEdge tmp_ = new Edge;
		pEdge tmp = new Edge;
		cin >> u >> v >> value;
		u--;
		v--;
		tmp->value = value;
		tmp->from = u;
		tmp->to = v;
		Graph[u].push_back(tmp);
		tmp_->value = value;
		tmp_->from = v;
		tmp_->to = u;
		Graph[v].push_back(tmp_);
	}
	for (int i(0); i < k; i++)
	{
		pEdge tmp = new Edge;
		cin >> u >> v;
		u--;
		v--;
		tmp->value = 0;
		tmp->from = u;
		tmp->to = v;
		Graph[u].push_back(tmp);
	}
	// 计算
	int* ans = SPFA(n, Graph, s);
	// 输出
	if (ans[n - 1] == INF)
		printf("%d\n", -1);
	else
		printf("%d\n", ans[n - 1]);
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