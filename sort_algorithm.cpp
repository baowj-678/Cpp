#include "sort_algorithm.h"
#include "basic_array_function.h"
#include <iostream>
#include <time.h>

using namespace::std;

int main()
{
	clock_t begin, end;
	int n = 21;
	int* nums = array_generate_int<int>(20 * 500);
	int* test = new int[20 * 500];
	double time = 0;
	for (int i(1); i < n; i++)
	{
		time = 0;
		int m = i * 500;
		for (int k = 0; k < 100; k++)
		{
			for (int j(0); j < m; j++)
				test[j] = nums[j];
			begin = clock();
			insertSort(test, m);
			end = clock();
			time += ((double)end - begin);
		}
		cout << time/CLOCKS_PER_SEC << ",";
	}
	delete[] nums;
	
}