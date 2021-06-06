/**
 * @author: Bao Wenjie
 * @date: 2021/6/4
 * @link: https://www.luogu.com.cn/problem/P1866
 */

#include <cstdio>
#include <algorithm>
#define MAXN 55
#define scanf scanf_s

bool cmp(long long a, long long b)
{
	return a < b;
}

long long nums[MAXN];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", nums + i);
	std::sort(nums, nums + n, cmp);
	long long sum = nums[0];
	for(int i = 1; i < n; i++)
	{
		sum = (sum * (nums[i] - i)) % 1000000007;
	}
	printf("%lld\n", sum);
}