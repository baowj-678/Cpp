#include <iostream>
#include <cstdlib>
#include "basic_array_function.h"
using namespace::std;


int* random_quick_sort(int* nums, int left, int right);
int main()
{
	int n = 90;
	int* nums = generate(n);
	print(nums, n);
	random_quick_sort(nums, 0, n - 1);
	print(nums, n);
	return 0;
}

int* random_quick_sort(int* nums, int left, int right)
{
	int p = left;
	int q = right;
	if (p >= q)
		return nums;
	int key = nums[right];
	while (true)
	{
		while (p < right && nums[p] <= key)
			p++;
		while (q > 0 && nums[q] >= key)
			q--;
		if (p < q)
		{
			int temp = nums[p];
			nums[p] = nums[q];
			nums[q] = temp;
		}
		else
		{
			break;
		}
	}
	nums[right] = nums[p];
	nums[p] = key;
	random_quick_sort(nums, left, p - 1);
	random_quick_sort(nums, p + 1, right);
	return nums;
}

