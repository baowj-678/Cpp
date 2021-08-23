/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> back;
	sort(nums.begin(), nums.end());
	//
	for (int i(0); i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
	//
	for (int i(0); i < nums.size();)
	{
		for (int j(i + 1),k(nums.size() - 1); j < k;)
		{
			if (nums[k] + nums[j] + nums[i] == 0)
			{
				if (!(!back.empty() && back.back()[0] == nums[i] && back.back()[1] == nums[j]))
				{
					back.push_back({ nums[i], nums[j], nums[k] });
				}
				k--;
				j++;
			}
			else if (nums[k] + nums[i] + nums[j] > 0)
			{
				k--;
			}
			else
			{
				j++;
			}
		}
		int temp = nums[i];
		while (i < nums.size() && temp == nums[i])
			i++;
	}
	return back;
}

int main()
{
	int n;
	cin >> n;
	vector<int> num;
	for (int i(0); i < n; i++)
	{
		int x;
		cin >> x;
		num.push_back(x);
	}
	vector<vector<int>> back = threeSum(num);
	for (int i(0); i < back.size(); i++)
	{
		for (int j(0); j < back[i].size(); j++)
		{
			cout << back[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

//acceped