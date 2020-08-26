/**
* Topic: CSP-2017-12-сно╥
* Author: Bao Wenjie
* Email: bwj_678@qq.com
* Date: 2020/8/26
*/
#include <iostream>
#include <queue>

using namespace::std;
int main()
{
	queue<int> Q;
	int n, k;
	cin >> n >> k;
	for (int i(1); i <= n; i++)
		Q.push(i);
	int call = 0;
	while (Q.size() > 1)
	{
		call++;
		int tmp = Q.front();
		Q.pop();
		if (call % k == 0 || call % 10 == k)
		{
			continue;
		}
		else
		{
			Q.push(tmp);
		}
	}
	cout << Q.front();
}