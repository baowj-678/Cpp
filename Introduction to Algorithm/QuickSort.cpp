/**
 * @author: Bao Wenjie
 * @date: 2021/5/21
 */

#include <cstdio>
#include <algorithm>
#define MAXN 1000

bool cmp(int a, int b)
{
	return a > b;
}

int get_mid(int* nums, int left, int right)
{
	int mid = (left + right);
	if(cmp(nums[right], nums[left]))
	{
		std::swap(nums[left], nums[right]);
	}
	if(cmp(nums[mid], nums[left]))
	{
		std::swap(nums[left], nums[mid]);
	}
	if(cmp(nums[right], nums[mid]))
	{
		std::swap(nums[mid], nums[right]);
	}
	return mid;
}

void quick_sort(int* nums, int left, int right)
{
	int p = left, q = right;
	int mid = get_mid(nums, left, right - 1);
	if (right - left <= 2)
		return;
	std::swap(nums[mid], nums[right - 2]);
	int key = nums[right - 2];
	while (true)
	{
		while (p < right && cmp(nums[p], key))
			p++;
		while (q > left && (!cmp(nums[q], key)))
			q--;
		if (p < q)
		{
			std::swap(nums[p], nums[q]);
		}
		else
		{
			break;
		}
	}
	nums[right - 2] = nums[p];
	nums[p] = key;
	quick_sort(nums, left, p + 1);
	quick_sort(nums, p + 1, right);
	return;
}

int nums[MAXN];
int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", nums + i);
	quick_sort(nums, 0, n);
	for (int i = 0; i < n; i++)
		printf("%d ", nums[i]);
	
}