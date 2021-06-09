/**
 * @author: Bao Wenjie
 * @date: 2021/6/9
 * @link: https://www.luogu.com.cn/problem/P1102
 */
#include <cstdio>
#include <algorithm>
#define MAXN 200050
#define scanf scanf_s

int nums[MAXN];
bool cmp(int a, int b)
{
	return a < b;
}

int search(int x, int n)
{
	int left_edge, right_edge;
	int left = 0, right = n - 1;
	while(left < right)
	{
		int half = (left + right) / 2;
		if(nums[half] > x)
		{
			right = half - 1;
		}
		else if(nums[half] < x)
		{
			left = half + 1;
		}
		else
		{
			right = half;
		}
	}
	if (nums[left] != x)
		return -1;
	left_edge = left;
	left = 0, right = n - 1;
	while(left < right)
	{
		int half = (left + right + 1) / 2;
		if(nums[half] > x)
		{
			right = half - 1;
		}
		else if(nums[half] < x)
		{
			left = half + 1;
		}
		else
		{
			left = half;
		}
	}
	right_edge = right;
	if (nums[right] != x)
		return -1;
	return right_edge - left_edge + 1;
}

int main()
{
	int n, C;
	scanf("%d%d", &n, &C);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", nums + i);
	}
	std::sort(nums, nums + n, cmp);
	long long sum = 0, last = 0;
	for(int i = 0; i < n; i++)
	{
		if(i > 0 && nums[i] == nums[i - 1])
		{
			sum += last;
		}
		else
		{
			last = 0;
			int tmp = search(nums[i] + C, n);
			if(tmp != -1)
			{
				last += tmp;
				sum += last;
			}
		}
	}
	printf("%lld", sum);
}