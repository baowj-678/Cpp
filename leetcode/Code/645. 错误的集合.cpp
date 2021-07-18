#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

bool cmp(int a, int b)
{
	return a < b;
 } 

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    	sort(nums.begin(), nums.end(), cmp);
    	vector<int> ans(2, -1);
    	if(nums[0] != 1)
    		ans[1] = 1;
    	for(int i = 1; i < nums.size() - 1; i++)
    	{
    		if(nums[i - 1] == nums[i] || nums[i] == nums[i + 1])
    		{
    			ans[0] = nums[i];
			}
			if(nums[i] - nums[i - 1] == 2)
			{
				ans[1] = nums[i] - 1;
			}
			if(nums[i + 1] - nums[i] == 2)
			{
				ans[1] = nums[i] + 1;
			}
		}
		if(nums[nums.size() - 1] == nums[nums.size() - 2])
		{
			ans[0] = nums[nums.size() - 1];
		}
		if(nums[nums.size() - 1] - nums[nums.size() - 2] == 2)
		{
			ans[1] = nums[nums.size() - 1] - 1;
		}
		if(ans[1] == -1)
			ans[1] = nums[nums.size() - 1] +1;
		return ans;
    }
};
