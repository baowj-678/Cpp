/**
* @Title: Hungarian算法
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/9/5
*/
#include <iostream>
#include <vector>
#include <set>

using namespace::std;
int* Hungarian(short** graph, int n, int m);
short** get_space(int n, int m);
void free_space(short** graph, int n, int m);
bool find_path(short** graph, int* X, int* Y, int* path_X, int* path_Y, int tmp, int xory, int n, int m);
int main()
{
	int n, m;
	cout << "请输入X结点数，Y结点数：" << endl;
	cin >> n >> m;
	int k;
	cout << "请输入边数：" << endl;
	cin >> k;
	short** graph = get_space(n, m);
	int x, y;
	cout << "请输入各边（0 3表示：X的0到Y的3）：" << endl;
	for (int i(0); i < k; i++)
	{
		cin >> x >> y;
		*(*(graph + x) + y) = 1;
	}
	int* X = Hungarian(graph, n, m);
	cout << "结果是：" << endl;
	for (int i(0); i < n; i++)cout << X[i] << " ";
	cout << endl;
	return 0;
}

/**
* 获取存储空间
*/
short** get_space(int n, int m)
{
	short** ans = new short* [n];
	for (int i(0); i < n; i++)ans[i] = new short[m];
	return ans;
}

/**
* 释放存储空间
*/
void free_space(short** graph, int n, int m)
{
	for (int i(0); i < n; i++)free(graph[i]);
	free(graph);
}

/**
* Hungarian算法
* @param:
* graph: n * m图
* n: X结点个数
* m: Y结点个数
* @return:
* X: X结点对应的Y结点
*/
int* Hungarian(short** graph, int n, int m)
{
	// 初始化
	int count = 0;
	int* X = new int[n];
	int* Y = new int[m];
	int* path_X = new int[n];
	int* path_Y = new int[m];
	memset(X, -1, sizeof(int) * n);
	memset(Y, -1, sizeof(int) * m);
	memset(path_X, 0, sizeof(int) * n);
	memset(path_Y, 0, sizeof(int) * m);
	// 循环
	for (int i(0); i < n; i++)
	{
		if (find_path(graph, X, Y, path_X, path_Y, i, 0, n, m))
		{
			memset(path_X, 0, sizeof(int) * n);
			memset(path_Y, 0, sizeof(int) * m);
		}
		else
		{
			break;
		}
	}
	return X;
}

/**
* DFS寻找增广路径
* @param:
* graph: 图
* X: 已连接的X结点(-1:未连接）
* Y: 已连接的Y结点
* path_X: 已访问的X结点(0:未访问，1:已访问)
* path_Y: 已访问的Y结点
* tmp: 当前访问结点
* xory: 当前访问结点输入X(0)、Y(1)
*/
bool find_path(short** graph, int* X, int* Y, int* path_X, int *path_Y, int tmp, int xory, int n, int m)
{
	bool is_find = false;
	// tmp是X的坐标
	if (xory == 0)
	{
		// 如果tmp点访问
		if (path_X[tmp] == 1)
			return false;
		// 标记tmp访问过
		path_X[tmp] = 1;

		// 遍历tmp的所有边
		short* graph_row = *(graph + tmp);
		for (int i(0); i < n; i++)
		{
			// tmp->i 有连接
			if (*(graph_row + i) == 1)
			{
				// i点在图中
				if (Y[i] != -1)
				{
					bool isOK = find_path(graph, X, Y, path_X, path_Y, i, 1, n, m);
					// 找到增广路径
					if (isOK)
					{
						X[tmp] = i;
						Y[i] = tmp;
						return true;
					}
				}
				// i点不在图中
				else
				{
					// 连接tmp -> i
					X[tmp] = i;
					Y[i] = tmp;
					return true;
				}
			}
		}
		// 还原tmp未访问
		path_X[tmp] = 0;
	}
	// tmp是Y的坐标
	else
	{
		// 如果tmp点访问
		if (path_Y[tmp] == 1)
			return false;
		// 标记tmp访问过
		path_Y[tmp] = 1;

		// 遍历tmp的所有边
		for (int i(0); i < n; i++)
		{
			// tmp->i 有连接
			if (*(*(graph + i) + tmp) == 1)
			{
				// i点在图中
				if (X[i] != -1)
				{
					bool isOK = find_path(graph, X, Y, path_X, path_Y, i, 0, n, m);
					// 找到增广路径
					if (isOK)
					{
						Y[tmp] = i;
						X[i] = tmp;
						return true;
					}
				}
				// i点不在图中
				else
				{
					// 连接tmp -> i
					Y[tmp] = i;
					X[i] = tmp;
					return true;
				}
			}
		}
		// 还原tmp未访问
		path_Y[tmp] = 0;
	}
	return false;
}