/**
* @Title: 差分约束(System of Difference Constrains)
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/9/2
*/
#include "SDC.h"
#include <iostream>
#include <vector>

using namespace::std;

int main()
{
	cout << "请输入变量个数：" << endl;
	int n;
	cin >> n;
	cout << "请输入约束方程个数：" << endl;
	int m;
	cin >> m;
	cout << "请输入约束方程（1 2 6.7代表，x1 - x1 <= 6.7）（从1开始）：" << endl;

	vector<vector<pEdge>> vec(n);
	for (int i(0); i < m; i++)
	{
		int x, y;
		double value;
		cin >> x >> y >> value;
		pEdge tmp = new Edge;
		tmp->from = y - 1;
		tmp->to = x - 1;
		tmp->value = value;
		vec[y - 1].push_back(tmp);
	}
	int* ans = SPFA(n, vec, 0);
	for (int i(0); i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}