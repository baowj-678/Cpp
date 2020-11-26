/**
* Topic: CSP-2018-9-再卖菜
* Author: Bao Wenjie
* Email: bwj_678@qq.com
* Date: 2020/8/21
*/

//问题描述
//在一条街上有n个卖菜的商店，按1至n的顺序排成一排，这些商店都卖一种蔬菜。
//第一天，每个商店都自己定了一个正整数的价格。店主们希望自己的菜价和其他商店的一致，第二天，每一家商店都会根据他自己和相邻商店的价格调整自己的价格。具体的，每家商店都会将第二天的菜价设置为自己和相邻商店第一天菜价的平均值（用去尾法取整）。
//注意，编号为1的商店只有一个相邻的商店2，编号为n的商店只有一个相邻的商店n - 1，其他编号为i的商店有两个相邻的商店i - 1和i + 1。
//给定第二天各个商店的菜价，可能存在不同的符合要求的第一天的菜价，请找到符合要求的第一天菜价中字典序最小的一种。
//字典序大小的定义：对于两个不同的价格序列(a1, a2, …, an)和(b1, b2, b3, …, bn)，若存在i(i >= 1), 使得ai < bi，且对于所有j < i，aj = bj，则认为第一个序列的字典序小于第二个序列。
//	输入格式
//	输入的第一行包含一个整数n，表示商店的数量。
//	第二行包含n个正整数，依次表示每个商店第二天的菜价。
//	输出格式
//	输出一行，包含n个正整数，依次表示每个商店第一天的菜价。
//	样例输入
//	8
//	2 2 1 3 4 9 10 13
//	样例输出
//	2 2 2 1 6 5 16 10
//	数据规模和约定
//	对于30% 的评测用例，2 <= n <= 5，第二天每个商店的菜价为不超过10的正整数；
//	对于60% 的评测用例，2 <= n <= 20，第二天每个商店的菜价为不超过100的正整数；
//	对于所有评测用例，2 <= n <= 300，第二天每个商店的菜价为不超过100的正整数。
//	请注意，以上都是给的第二天菜价的范围，第一天菜价可能会超过此范围。
#include <iostream>
#include <vector>

using namespace::std;
const int N = 300 + 10;
const int M = 2000 + 10;

struct Edge {
	int from;
	int to;
	int value;
};

typedef Edge* pEdge;
void addEdge(int u, int v, int value, vector<vector<pEdge>>& Graph);
int main()
{
	// 输入
	int n;
	scanf_s("%d", &n);
	int Cost[N];
	vector<vector<pEdge>> Graph(n + 1);
	int value;
	for (int i = 1; i < n; i++)
	{
		scanf_s("%d", Cost + i);
	}
	// 转成图
	addEdge(0, 2, 2 * Cost[0], Graph);
	addEdge(2, 0, -2 * Cost[0] - 1, Graph);
	for (int i(1); i < n - 1; i++)
	{
		addEdge(i - 1, i + 2, 3 * Cost[i], Graph);
		addEdge(i + 2, i - 1, -3 * Cost[i] - 2, Graph);
	}
	addEdge(n - 2, n, 2 * Cost[n], Graph);
	addEdge(n, n - 2, -2 * Cost[n] - 1, Graph);



}

/**
* 向图中添加边
*/
void addEdge(int u, int v, int value, vector<vector<pEdge>>& Graph)
{
	pEdge tmp = new Edge;
	tmp->from = u;
	tmp->to = v;
	tmp->value = value;
	Graph[u].push_back(tmp);
}