/**
 * @author: Bao Wenjie
 * @date: 2021/5/27
 * @link: https://www.luogu.com.cn/problem/P1464
 */
#include <cstdio>
#define LL long long
#define MAXN 25
#define scanf scanf_s

LL dp[MAXN][MAXN][MAXN];
bool isV[MAXN][MAXN][MAXN];

LL w(LL a, LL b, LL c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if(a > 20 || b > 20 || c > 20)
	{
		return w(20, 20, 20);
	}
	if (isV[a][b][c])
		return dp[a][b][c];
	else
	{
		if(a < b && b < c)
		{
			dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
			isV[a][b][c] = true;
		}
		else
		{
			dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
			isV[a][b][c] = true;
		}
		return dp[a][b][c];
	}
}

int main()
{
	LL a, b, c;
	while(true)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		if(a == -1 && b == -1 && c == -1)
		{
			break;
		}
		printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
	}
	return 0;
}