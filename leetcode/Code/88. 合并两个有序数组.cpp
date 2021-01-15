#include <iostream>
#include <vector>

using namespace::std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int sum = m + n - 1;
	m--;
	n--;
	while (m >= 0 && n >= 0)
	{
		if (nums1[m] > nums2[n])
		{
			nums1[sum--] = nums1[m--];
		}
		else
		{
			nums1[sum--] = nums2[n--];
		}
	}
	while (n >= 0)
	{
		nums1[sum--] = nums2[n--];
	}
}


int main()
{
	vector<int> nums1, nums2;
	int num1, num2;
	cin >> num1 >> num2;
	for (int i(0); i < num1; i++)
	{
		int x;
		cin >> x;
		nums1.push_back(x);
	}
	for (int i(0); i < num2; i++)
	{
		int x;
		cin >> x;
		nums2.push_back(x);
		nums1.push_back(0);
	}
	merge(nums1, num1, nums2, num2);
	for (int i(0); i < num1 + num2; i++)
	{
		cout << nums1[i];
	}
}