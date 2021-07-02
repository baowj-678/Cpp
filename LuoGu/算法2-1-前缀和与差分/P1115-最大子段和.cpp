/**
 * @author: Bao Wenjie
 * @date: 2021/7/1
 * @link: https://www.luogu.com.cn/problem/P1115
 */
#include <cstdio>
#include <algorithm>
#define scanf scanf_s

int main()
{
	int n, sum = 0, max_sum = -2000000010;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		sum += tmp;
		max_sum = std::max(max_sum, sum);
		if (sum < 0)
			sum = 0;
	}
	printf("%d\n", max_sum);
}