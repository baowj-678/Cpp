/**
 * @author: Bao Wenjie
 * @date: 2021/5/25
 * @link: https://www.luogu.com.cn/problem/P1439
 */
#include <cstdio>
#include <vector>
#define MAXN 100050
#define scanf scanf_s

int a[MAXN];
int map[MAXN];
int dp[MAXN];

int main()
{
	int n, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		map[x] = i;
	}
	dp[0] = a[0];
	int len = 1;
	for(int i = 1; i < n; i++)
	{
		x = a[i];
		y = map[x];
		if(y > map[dp[len - 1]])
		{
			dp[len++] = x;
		}
		else
		{
			for(int j = 0; j < len; j++)
			{
				if(y <= map[dp[j]])
				{
					dp[j] = x;
					break;
				}
			}
		}
	}
	printf("%d\n", len);
}
