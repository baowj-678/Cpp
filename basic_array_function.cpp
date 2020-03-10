#include <iostream>
#include "basic_array_function.h"

using namespace::std;

void array_print(element* nums, int n)
{
	for (int i(0); i < n; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}
element* array_generate(int n)
{
	element* nums = new element[n];
	for (int i(0); i < n; i++)
	{
		nums[i] = i;
	}
	for (int i(0); i < n / 2; i++)
	{
		int p = rand() % n;
		int q = rand() % n;
		int temp = nums[p];
		nums[p] = nums[q];
		nums[q] = temp;
	}
	return nums;
}