/**
 * @author: Bao Wenjie
 * @date: 2021/5/24
 * @link: https://www.luogu.com.cn/problem/P1233
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 5050
#define scanf scanf_s

struct point
{
	int x;
	int y;
}points[MAXN];

bool cmp(point& a, point& b)
{
	if (a.x > b.x)
		return true;
	else if (a.x < b.x)
		return false;
	else
		return a.y > b.y;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &(points[i].x), &(points[i].y));
	}
	std::sort(points, points + n, cmp);

	std::vector<int> dp;
	dp.push_back(points[0].y);
	for(int i = 1; i < n; i++)
	{
		int tmp = points[i].y;
		if(tmp > dp.back())
		{
			dp.push_back(tmp);
		}
		else
		{
			int j = 0;
			for(; j < dp.size(); j++)
			{
				if (dp[j] >= tmp)
				{
					dp[j] = tmp;
					break;
				}
			}
		}
	}
	printf("%d\n", dp.size());
	return 0;
}