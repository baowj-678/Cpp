/**
 * @author: Bao Wenjie
 * @date: 2021/7/1
 * @link: https://www.luogu.com.cn/problem/P5638
 */
#include <cstdio>
#include <queue>
#include <algorithm>
#define scanf scanf_s

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	std::queue<long long> Q;
	long long total_sum = 0;
	long long k_sum = 0, k_sum_max = 0;
	for(int i = 0; i < n - 1; i++)
	{
		long long tmp;
		scanf("%lld", &tmp);
		total_sum += tmp;
		k_sum += tmp;
		Q.push(tmp);
		if(Q.size() > k)
		{
			k_sum -= Q.front();
			Q.pop();
		}
		k_sum_max = std::max(k_sum_max, k_sum);
	}
	printf("%lld\n", total_sum - k_sum_max);
}