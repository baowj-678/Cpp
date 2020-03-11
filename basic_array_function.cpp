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

element** create_two_dim_array(int x, int y)
{
	element** array = new element * [x];
	if (array != NULL)
	{
		for (int i(0); i < x; i++)
		{
			array[i] = new element[y];
			if (array[i] == NULL)
				return NULL;
		}
	}
	else
	{
		return NULL;
	}
	return array;
}
bool del_two_dim_array(element** array, int x)
{
	for (int i(0); i < x; i++)
	{
		if (array[i] != NULL)
			delete(array[i]);
		else
			return false;
	}
	delete(array);
	return true;
}

void array_print_two_dim(element** nums, int x, int y)
{
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%4d", nums[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}
