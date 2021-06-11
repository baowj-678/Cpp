/**
 * @author: Bao Wenjie
 * @date: 2021/6/11
 * @link: https://www.luogu.com.cn/problem/P2415
 */
#include <cstdio>
#define MAXN 40
#define scanf scanf_s

int set[MAXN];

int main()
{
	int i = 0, tmp;
	long long sum = 0;
	while (scanf("%d", &tmp) != EOF)
	{
		i++;
		sum += tmp;
	}
	for(int j = 0; j < i - 1; j++)
	{
		sum *= 2;
	}
	printf("%lld\n", sum);
	return 0;
}

