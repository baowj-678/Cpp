/**
 * @author: Bao Wenjie
 * @date: 2021/6/25
 * @link: https://www.luogu.com.cn/problem/P1199
 */
#include <cstdio>
#include <algorithm>
#define MAXN 550
#define scanf scanf_s

int score[MAXN][MAXN];

int main()
{
	int n, max_total = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			scanf("%d", &max_total);
			score[i][j] = score[j][i] = max_total;
		}
	}
	max_total = 0;
	for(int i = 0; i < n; i++)
	{
		int max_1 = 0, max_2 = 0;
		for(int j = 0; j < n; j++)
		{
			int tmp = score[i][j];
			if (tmp > max_1)
			{
				max_2 = max_1;
				max_1 = tmp;
			}
			else
			{
				max_2 = std::max(max_2, tmp);
			}
		}
		max_total = std::max(max_total, max_2);
	}
	printf("1\n%d\n", max_total);
}