#pragma once
#ifndef BASIC_ARRAY_FUNC
#define BASIC_ARRAY_FUNC
#include <iostream>
#include <iomanip>
using namespace::std;

template<typename element>
void array_print(element* nums, int n)
{
	for (int i(0); i < n; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}

template<typename element>
element* array_generate_int(int n)
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
		element temp = nums[p];
		nums[p] = nums[q];
		nums[q] = temp;
	}
	return nums;
}

template<typename element>
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

template<typename element>
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

template<typename element>
void array_print_two_dim(element** nums, int x, int y)
{
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			cout << setw(13) << nums[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

template<typename element>
element* array_generate_double(int n, double begin, double end)
{
	element* nums = new element[n];
	double delta = (end - begin) / n;
	for (int i(0); i < n; i++)
	{
		nums[i] = begin + i * delta;
	}
	for (int i(0); i < n / 2; i++)
	{
		int p = rand() % n;
		int q = rand() % n;
		element temp = nums[p];
		nums[p] = nums[q];
		nums[q] = temp;
	}
	return nums;
}

#endif // !BASIC_ARRAY_FUNC

