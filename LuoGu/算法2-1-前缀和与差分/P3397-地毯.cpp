/**
 * @author: Bao Wenjie
 * @date: 2021/7/1
 * @link: https://www.luogu.com.cn/problem/P3397
 */
#include <cstdio>
#define MAXN 1010
#define scanf scanf_s

int G[MAXN][MAXN];

int main()
{
	int n, m, x_1, y_1, x_2, y_2;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d%d%d", &x_1, &y_1, &x_2, &y_2);
		for(int x_i = x_1 - 1; x_i < x_2; x_i++)
		{
			for(int y_i = y_1 - 1; y_i < y_2; y_i++)
			{
				G[x_i][y_i]++;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
}