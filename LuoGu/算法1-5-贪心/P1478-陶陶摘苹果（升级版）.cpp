/**
 * @author: Bao Wenjie
 * @date: 2021/6/8
 * @llink: https://www.luogu.com.cn/problem/P1478
 */

#include <cstdio>
#include <algorithm>
#define MAXN 5050
#define scanf scanf_s

typedef struct tree
{
	int height;
	int y;
}tree;

tree trees[MAXN];

bool cmp(tree& a, tree& b)
{
	return a.y < b.y;
}

int main()
{
	int n, s, a, b, len = 0, x, y;
	scanf("%d%d%d%d", &n, &s, &a, &b);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		if(x <= a + b)
		{
			trees[len].height = x;
			trees[len].y = y;
			len++;
		}
	}
	std::sort(trees, trees + len, cmp);
	n = 0;
	for(int i = 0; i < len; i++)
	{
		if(trees[i].y <= s)
		{
			s -= trees[i].y;
			n++;
		}
		else
		{
			break;
		}
	}
	printf("%d\n", n);
}
