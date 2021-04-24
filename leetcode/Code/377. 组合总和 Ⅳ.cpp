/**
 * Author: Bao Wenjie
 * Date: 2021/4/24
 * Link: https://leetcode-cn.com/problems/combination-sum-iv/
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
    	for(int i = 0; i <= target; i++)
    	{
    		for(int j = 0; j < nums.size(); j++)
    		{
    			if(nums[j] > i)
    			{
                    break;
    			}
                else
                {
                    dp[i] += dp[i - nums[j]] > 2147483648 ? 0 : dp[i - nums[j]];
                }
    		}
    	}
        return dp[target];
    }
};