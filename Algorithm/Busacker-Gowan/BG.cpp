/**
* @Title: 求解最小费用最大流的Busacker-Gowan算法
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/9/4
*/
#include <iostream>
#include <queue>

#define	INF	1e17
#define E	0.0001

using namespace::std;
double** get_space(int n, int m);
void free_space(double** matrix, int n, int m);
double** Busacker_Gowan(double** contain_graph, double** cost_graph, int n, int s, int t);
int main()
{
	int n, m, s, t;
	cout << "请输入图结点数：" << endl;
	cin >> n;
	cout << "请输入起点和终点：" << endl;
	cin >> s >> t;
	double** contain_graph = get_space(n, n);
	double** cost_graph = get_space(n, n);
	for (int i(0); i < n; i++)
		for (int j(0); j < n; j++)
		{
			*(*(cost_graph + i) + j) = INF;
			*(*(contain_graph + i) + j) = 0;
		}
	cout << "请输入边数：" << endl;
	cin >> m;
	cout << "请输入边（例如0 1 3 4，代表0-1，最大容量是3，费用为4）：" << endl;
	int x, y, a, b;
	for (int i(0); i < m; i++)
	{
		cin >> x >> y;
		cin >> a >> b;
		*(*(contain_graph + x) + y) = a;
		*(*(cost_graph + x) + y) = b;
		*(*(cost_graph + y) + x) = -b;
	}
	double** graph = Busacker_Gowan(contain_graph, cost_graph, n, s, t);
	cout << "最小费用最大流为：" << endl;
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
			cout << graph[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	return 0;
}


/**
* 获取矩阵空间
*/
double** get_space(int n, int m)
{
	double** ans = new double* [n];
	for (int i(0); i < n; i++)
	{
		ans[i] = new double[m];
	}
	return ans;
}

/**
* 删除矩阵空间
*/
void free_space(double** matrix, int n, int m)
{
	for (int i(0); i < n; i++)
		free(matrix[i]);
	free(matrix);
}

/**
* @function: Busacker Gowan算法
* @param:
* contain_graph: 边的容量矩阵
* cost_graph: 边的费用矩阵
* n: 结点个数
* s: 起点
* t: 终点
* @return:
* graph: 每条边的最佳容量矩阵
*/
double** Busacker_Gowan(double** contain_graph, double** cost_graph, int n, int s, int t)
{
	// 初始化
	double** graph = get_space(n, n);
	double** cost_graph_tmp = get_space(n, n);
	for (int i(0); i < n; i++)
		for (int j(0); j < n; j++)
		{
			*(*(graph + i) + j) = 0;
			*(*(cost_graph_tmp + i) + j) = abs(*(*(contain_graph + i) + j) - 0) > E ? *(*(cost_graph + i) + j) : INF;
		}
	queue<int> Q;
	/**
	* 记录每个结点遍历次数
	*/
	int* count = new int[n];
	double* shortest = new double[n];
	int* path = new int[n];
	// 循环
	while (true)
	{
		// 寻找增广路径
		Q.push(s);
		memset(count, 0, sizeof(int) * n);
		for (int i(0); i < n; i++)
			shortest[i] = INF;
		shortest[s] = 0;
		memset(path, -1, sizeof(int) * n);
		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			double* cost_edges = *(cost_graph_tmp + u);
			for (int i(0); i < n; i++)
			{
				if (abs(*(cost_edges + i) - INF) < E)
					continue;
				double value = shortest[u] + *(cost_edges + i);
				if (value < shortest[i])
				{
					shortest[i] = value;
					path[i] = u;
					if (count[i] > n)
					{
						goto out;
					}
					count[i]++;
					Q.push(i);
				}
			}
		}
	out:
		int tmp = shortest[t];
		// 找到最佳路径
		if (Q.empty() && shortest[t] != INF)
		{
			double add_flow = INF;
			double value;
			int v = t;
			int u = path[v];
			while (u != -1)
			{
				value = *(*(contain_graph + u) + v) - *(*(graph + u) + v);
				if (value < add_flow)
					add_flow = value;
				v = u;
				u = path[v];
			}
			v = t;
			u = path[v];
			while (u != -1)
			{
				*(*(graph + u) + v) += add_flow;
				*(*(graph + v) + u) -= add_flow;
				if (*(*(graph + u) + v) == *(*(contain_graph + u) + v))
					*(*(cost_graph_tmp + u) + v) = INF;
				else
					*(*(cost_graph_tmp + u) + v) = *(*(cost_graph + u) + v);

				if (*(*(graph + v) + u) == *(*(contain_graph + v) + u))
					*(*(cost_graph_tmp + v) + u) = INF;
				else
					*(*(cost_graph_tmp + v) + u) = *(*(cost_graph + v) + u);
				v = u;
				u = path[v];
			}
		}
		else
		{
			break;
		}
	}
	for (int i(0); i < n; i++)
		for (int j(0); j < n; j++)
			if (*(*(graph + i) + j) < 0)
				*(*(graph + i) + j) = 0;
	return graph;
}

/**
测试用例：
5
0 4
6
0 1 2 4
0 2 8 1
1 4 4 2
2 1 9 2
2 3 10 3
3 4 8 2
结果：
0 2 8 0 0
0 0 0 0 4
0 2 0 6 0
0 0 0 0 6
0 0 0 0 0
*/