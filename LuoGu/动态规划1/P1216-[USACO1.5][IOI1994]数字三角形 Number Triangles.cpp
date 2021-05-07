/**
 * @author: Bao Wenjie
 * @date: 2021/5/7
 * @link: https://www.luogu.com.cn/problem/P1216
 */

#include <cstdio>
#include <algorithm>
#define scanf scanf_s

const int MAXR = 1005;
int dp[MAXR] = { 0 };
int main()
{
	int r, x, tmp, last;
	scanf("%d", &r);
	for(int i = 1; i <= r; i++)
	{
		last = 0;
		for (int j = 0; j < i; j++)
		{
			scanf("%d", &x);
			tmp = std::max(last, dp[j]);
			last = dp[j];
			dp[j] = tmp + x;
		}
	}
	x = 0;
	for(int i = 0; i < r; i++)
	{
		x = std::max(x, dp[i]);
	}
	printf("%d\n", x);
	return 0;
}