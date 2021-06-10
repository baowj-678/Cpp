/**
 * @author: Bao Wenjie
 * @date: 2021/6/9
 * @link: https://www.luogu.com.cn/problem/P2241
 */
#include <cstdio>
#include <algorithm>
#define scanf scanf_s

int main()
{
	long long square = 0, rectangle = 0;
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			square += std::min(n - i, m - j);
			rectangle += ((n - i) * (m - j) - std::min(n - i, m - j));
		}
	}
	printf("%lld %lld\n", square, rectangle);
	return 0;
}