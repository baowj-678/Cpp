#pragma once
#ifndef BASIC_ARRAY_FUNC
#define BASIC_ARRAY_FUNC
#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace::std;

template<typename element>
void printOneDimArray(element* nums, int n)
{
	for (int i(0); i < n; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}

template<typename element>
element* shuffleOneDimArray(element nums[], int n)
{
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
element* randomOneDimArrayInt(int n)
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
element** zerosTwoDimMatrix(int x, int y)
{
	element** array = new element * [x];
	if (array != NULL)
	{
		for (int i(0); i < x; i++)
		{
			array[i] = new element[y];
			if (array[i] == NULL)
				return NULL;
			else
				memset(array[i], 0, y*sizeof(element));
		}
	}
	else
	{
		return NULL;
	}
	return array;
}

template<typename element>
bool delTwoDimMatrix(element** array, int x)
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
void printTwoDimMatrix(element** nums, int x, int y, int width = 4)
{
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			cout << setiosflags(ios::left) << setw(width) << nums[i][j];
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
	shuffleOneDimArray<element>(nums, n);
	return nums;
}

template<typename element>
element** array_two_dim_generate_double(int n, double begin, double end)
{
	element** array = new element * [n];
	for (int i(0); i < n; i++)
	{
		array[i] = array_generate_double<element>(n, begin, end);
	}
	return array;
}



#endif // !BASIC_ARRAY_FUNC

