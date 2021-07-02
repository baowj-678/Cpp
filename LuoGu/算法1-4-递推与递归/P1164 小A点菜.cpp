/**
 * @author: Bao Wenjie
 * @date: 2021/6/28
 * @link: https://www.luogu.com.cn/problem/P1164
 */
#include <cstdio>
#define MAXN 10050
#define scanf scanf_s

int nums[MAXN];

int main()
{
	int M, N;
	scanf("%d%d", &N, &M);
	nums[0] = 1;
	for(int i = 0; i < N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		for(int j = M; j >= tmp; j--)
		{
			nums[j] += nums[j - tmp];
		}
	}
	printf("%d\n", nums[M]);
}