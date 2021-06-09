/**
 * @author: Bao Wenjie
 * @date: 2021/6/9
 * @link: https://www.luogu.com.cn/problem/P2249
 */

#include <cstdio>
#define MAXN 1000050
#define scanf scanf_s

int nums[MAXN];

int search(int x, int n)
{
	int left = 0, right = n;
	while(left < right)
	{
		int half = (left + right) / 2;
		if(nums[half] < x)
		{
			left = half + 1;
		}
		else if(nums[half] > x)
		{
			right = half - 1;
		}
		else
		{
			right = half;
		}
	}
	if (nums[left] != x)
		return -2;
	return left;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i  = 0; i < n; i++)
	{
		scanf("%d", nums + i);
	}
	for(int i = 0; i < m; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		printf("%d ", search(tmp, n - 1) + 1);
	}
	return 0;
}