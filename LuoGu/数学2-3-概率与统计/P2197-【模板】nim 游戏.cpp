/**
 * @author: Bao Wenjie
 * @date: 2021/6/26
 * @link: https://www.luogu.com.cn/problem/P2197
 */
#include <cstdio>
#define scanf scanf_s


int main()
{
	int T, n, sum = 0;
	scanf("%d", &T);
	for(int i = 0; i < T; i++)
	{
		scanf("%d", &n);
		sum = 0;
		for(int j = 0; j < n; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			sum ^= tmp;
		}
		if (sum == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
}