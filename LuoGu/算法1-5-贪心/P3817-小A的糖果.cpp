/**
 * @author: Bao Wenjie
 * @date: 2021/6/8
 * @link: https://www.luogu.com.cn/problem/P3817
 */

#include <cstdio>
#define MAXN 100050
#define scanf scanf_s

int A[MAXN];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", A + i);
	}
	long long cnt = 0;
	for(int i = 1; i < n; i++)
	{
		int gap = A[i] + A[i - 1] - k;
		if(gap > 0)
		{
			cnt += gap;
			if (A[i] < gap)
				A[i] = 0;
			else
				A[i] -= gap;
		}
	}
	printf("%lld\n", cnt);
}