/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
*/

#include <iostream>
#include <vector>

using namespace::std;

void moveZeroes(vector<int>& nums) 
{
	int point2zero = 0;
	int point2nums = 0;
	for (; point2nums < nums.size(); point2nums++)
	{
		if (nums[point2nums] != 0)
		{
			if (point2nums == point2zero)
			{
				point2zero++;
				continue;
			}
			if (nums[point2zero] == 0)
			{
				nums[point2zero] = nums[point2nums];
				nums[point2nums] = 0;
				point2zero++;
			}
			else
			{
				while (point2zero < point2nums && nums[point2zero] == 0)
					point2zero++;
				nums[point2zero] = nums[point2nums];
				nums[point2nums] = 0;
				point2zero++;
			}
		}
	}
}

void moveZeroesBetter(vector<int>& nums)
{
	int point2ok = 0;
	for (int i(0); i < nums.size(); i++)
	{
		if (nums[i] > 0)
		{
			int temp = nums[i];
			nums[i] = 0;
			nums[point2ok] = temp;
			point2ok++;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int x;
	vector<int> nums;
	for (int i(0); i < n; i++)
	{
		cin >> x;
		nums.push_back(x);
	}
	moveZeroesBetter(nums);
	for (int i(0); i < n; i++)
	{
		cout << nums[i] << " ";
	}
}

//accepted