#include <iostream>
#include <vector>

using namespace::std;

int searchInsert(vector<int>& nums, int target) {
	int begin = 0, end = nums.size() - 1;
	int mid = (begin + end) / 2;
	if (nums[begin] > target)
		return begin;
	if (nums[end] < target)
		return end + 1;
	while (target != nums[mid])
	{
		if (mid == begin)
		{
			mid = end;
			break;
		}
		if (target > nums[mid])
		{
			begin = mid;
		}
		else if (target < nums[mid])
		{
			end = mid;
		}
		mid = (begin + end) / 2;
	}
	return mid;
}

int main()
{
	vector<int> nums;
	int n;
	cin >> n;
	for (int i(0); i < n; i++)
	{
		int x;
		cin >> x;
		nums.push_back(x);
	}
	int target;
	cin >> target;
	cout << searchInsert(nums, target);
}