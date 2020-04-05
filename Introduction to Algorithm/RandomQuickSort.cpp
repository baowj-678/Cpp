#include "SortAlgorithm.h"
#include <iostream>

using namespace::std;
int* random_quick_sort(int* nums, int left, int right);

int main_random_quick_sort()
{
	cout << "Random Quick sort" << endl << "n: " << endl;
	int n;
	cin >> n;
	while (n != 0)
	{
		int* s = new int[n];
		for (int i(0); i < n; i++)
		{
			cin >> s[i];
		}
		random_quick_sort(s, 0, n - 1);
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

int* random_quick_sort(int* nums, int left, int right)
{
	int p = left;
	int q = right;
	if (p >= q)
		return nums;
	int temp = rand() % (right - left + 1) + left;
	int key = nums[temp];
	nums[temp] = nums[right];
	nums[right] = key;
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
