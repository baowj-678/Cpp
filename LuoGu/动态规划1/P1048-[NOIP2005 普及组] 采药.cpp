/**
* @author: Bao Wenjie
* @date: 2021/5/9
* @link: https://www.luogu.com.cn/problem/P1048
*/

#include <cstdio>
#include <algorithm>
#define scanf scanf_s

using namespace::std;

int times[105];
int values[105];
int dp[105][1005] = { 0 };
int main()
{
	int M, T;
	scanf("%d%d", &T, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", times + i, values + i);
	}
	for (int j = times[0]; j <= T; j++)
	{
		dp[0][j] = values[0];
	}
	for (int i = 1; i < M; i++)
	{
		for (int j = 1; j < times[i]; j++)
			dp[i][j] = dp[i - 1][j];
		for (int j = times[i]; j <= T; j++)
		{
			dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - times[i]] + values[i]);
		}
	}
	printf("%d\n", dp[M - 1][T]);
	return 0;
}