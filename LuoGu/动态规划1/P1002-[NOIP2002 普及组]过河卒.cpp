/**
 * @author: Bao Wenjie
 * @date: 2021/5/17
 * @link: https://www.luogu.com.cn/problem/P1002
 */

#include <cstdio>
#include <algorithm>
#define MAXN 30
#define scanf scanf_s


long long dp[MAXN][MAXN];
int main()
{
	int B_x, B_y, H_x, H_y;
	dp[0][0] = 1;
	scanf("%d%d%d%d", &B_x, &B_y, &H_x, &H_y);
	for(int i = 0; i <= B_x; i++)
	{
		for(int j = 0; j <= B_y; j++)
		{
			if(i == 0 && j == 0)
				continue;;
			long long d_x = abs(H_x - i);
			long long d_y = abs(H_y - j);
			if((d_x == 1 && d_y == 2) || 
				(d_x == 2 && d_y == 1) ||
				(d_x == 0 && d_y == 0))
			{
				dp[i][j] = 0;
			}
			else
			{
				d_x = i - 1 >= 0 ? dp[i - 1][j] : 0;
				d_y = j - 1 >= 0 ? dp[i][j - 1] : 0;
				dp[i][j] = d_x + d_y;
			}
		}
	}

	printf("%lld", dp[B_x][B_y]);
}