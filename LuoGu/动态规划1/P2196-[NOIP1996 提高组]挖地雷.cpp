/**
 * @author: Bao Wenjie
 * @date: 2021/5/18
 * @link: https://www.luogu.com.cn/problem/P2196
 */

#include <cstdio>
#include <algorithm>
#define scanf scanf_s
#define MAXN 25

int father[MAXN];
int nums[MAXN];
int dp[MAXN] = { 0 };

void print(int i)
{
	if (father[i] != -1)
		print(father[i]);
	printf("%d ", i + 1);
}

int main()
{
	int N, x;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		father[i] = -1;
		scanf("%d", nums + i);
		dp[i] = nums[i];
	}
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = i + 1; j < N; j++)
		{
			scanf("%d", &x);
			if(x == 1)
			{
				if (dp[i] + nums[j] > dp[j])
				{
					dp[j] = dp[i] + nums[j];
					father[j] = i;
				}
			}
		}
	}
	int max_ = 0, max_i = 0;
	for (int i = 0; i < N; i++)
		if(dp[i] > max_)
		{
			max_ = dp[i];
			max_i = i;
		}
	print(max_i);
	printf("\n");
	printf("%d\n", max_);
	return 0;
}