/**
 * @author: Bao Wenjie
 * @date: 2021/6/4
 * @link: https://www.luogu.com.cn/problem/P3913
 */

#include <cstdio>
#include <algorithm>
#define MAXN 1000050
#define LL long long
#define scanf scanf_s

int R[MAXN];
int C[MAXN];

int main()
{
	LL N, K;
	scanf("%lld%lld", &N, &K);
	for(int i = 0; i < K; i++)
	{
		scanf("%d%d", R + i, C + i);
	}
	std::sort(R, R + K);
	std::sort(C, C + K);
	int rCount = 0, cCount = 0;
	for(int i = 1; i < K; i++)
	{
		if (C[i] == C[i - 1])
			cCount++;
	}
	for(int i = 1; i < K; i++)
	{
		if (R[i] == R[i - 1])
			rCount++;
	}
	LL sum = ((K - rCount) + (K - cCount)) * N;
	sum -= (K - rCount) * (K - cCount);
	printf("%lld\n", sum);
	return 0;
}