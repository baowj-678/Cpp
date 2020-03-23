#include <iostream>
#include <vector>

/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例 :

输入: [-2, 1, -3, 4, -1, 2, 1, -5, 4] ,
输出 : 6
解释 : 连续子数组 [4, -1, 2, 1] 的和最大，为 6。
*/

using namespace::std;

int maxSubArray(vector<int>& nums) 
{
	int max = 0, currMax = 0;
	for (int i(0); i < nums.size(); i++)
	{
		currMax += nums[i];
		if (currMax > max)
			max = currMax;
		else if (currMax < 0)
			currMax = 0;
	}
	if (max == 0)
	{
		max = nums[0];
		for (int i(0); i < nums.size(); i++)
		{
			if (nums[i] > max)
				max = nums[i];
		}
	}
	return max;
}

int main()
{
	vector<int> s;
	int n;
	cin >> n;
	for (int i(0); i < n; i++)
	{
		int x;
		cin >> x;
		s.push_back(x);
	}
	cout << maxSubArray(s) << endl;
}

//accepted

