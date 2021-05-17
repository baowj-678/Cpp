/**
 * @author: Bao Wenjie
 * @date: 2021/5/14
 * @link: https://www.luogu.com.cn/problem/P1616
 */

#include <cstdio>
#include <algorithm>
#define scanf scanf_s
#define LL long long

const int MAXN = 1e7 + 5;
LL dp[MAXN] = { 0 };

int main()
{
	int t, m, a, b;
	scanf("%d%d", &t, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		for(int j = a; j <= t; j++)
		{
			dp[j] = std::max(dp[j], dp[j - a] + b);
		}
	}
	printf("%lld", dp[t]);
}