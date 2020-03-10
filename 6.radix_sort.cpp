#include <iostream>
#include "basic_array_function.h"
using namespace::std;

int* radix_sort(int *sum, int n, int space[8][100]);
int main()
{
	int n;
	n = 90;
	int* nums = generate(n);
	int space[8][100];
	print(nums, n);
	radix_sort(nums, n, space);
	print(nums, n);
	
}

int* radix_sort(int* nums, int n, int space[8][100])
{
	for (int i(0); i < 8; i++)
		space[i][0] = 1;
	int max = 0;
	for (int i(0); i < n; i++)
	{
		if (max < nums[i])
			max = nums[i];
		int key = nums[i] & 0b111;
		space[key][space[key][0]++] = nums[i];
	}
	int k = 0;
	for (int i(0); i < 8; i++)
	{
		for (int j(1); j < space[i][0];j++)
		{
			nums[k++] = space[i][j];
		}
		space[i][0] = 1;
	}
	// the biggest number's radix
	int max_radix = 0;
	for (; max > 0;max_radix++)
	{
		max /= 8;
	}
	for (int k(1); k < max_radix; k++)
	{
		for (int i(0); i < n; i++)
		{
			int key = (nums[i] >>(3 * k) & 0b111);
			space[key][space[key][0]++] = nums[i];
		}
		int t = 0;
		for (int i(0); i < 8; i++)
		{
			for (int j(1); j < space[i][0]; j++)
			{
				nums[t++] = space[i][j];
			}
			space[i][0] = 1;
		}
	}
	return nums;
}