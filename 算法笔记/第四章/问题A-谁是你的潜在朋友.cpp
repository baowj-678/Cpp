/**
* Author: Bao Wenjie
* Date: 2021/1/16
* Link: http://codeup.cn/problem.php?cid=100000582&pid=0
*/

#include <cstdio>
#include <unordered_map>
using namespace::std;

int main()
{
	int n, m;
	int f[2100];
	unordered_map<int, int> map;
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		map.clear();
		for (int i(0); i < n; i++)
		{
			int x;
			scanf_s("%d", &x);
			f[i] = x;
			auto p = map.find(x);
			if (p == map.end())
			{
				map.insert(pair<int, int>{x, 1});
			}
			else
			{
				p->second++;
			}
		}
		for (int i(0); i < n; i++)
		{
			if (map[f[i]] - 1 <= 0)
				printf("BeiJu\n");
			else
				printf("%d\n", map[f[i]] - 1);
		}
	}
	return 0;
}