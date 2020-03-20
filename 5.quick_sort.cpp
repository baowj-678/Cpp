#include <iostream>
#include <cstdlib>
#include "basic_array_function.h"
using namespace::std;


int* quick_sort(int* nums, int left, int right);
int main_quick_sort()
{
	cout << "Quick sort" << endl << "n: " << endl;
	int n;
	cin >> n;
	while (n != 0)
	{
		int* s = new int[n];
		for (int i(0); i < n; i++)
		{
			cin >> s[i];
		}
		quick_sort(s, 0, n - 1);
		cout << "ans:" << endl;
		for (int i(0); i < n; i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;
		cout << "n:" << endl;
		cin >> n;
	}
	return 0;
}

int* quick_sort(int* nums, int left, int right)
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
	quick_sort(nums, left, p - 1);
	quick_sort(nums, p + 1, right);
	return nums;
}

