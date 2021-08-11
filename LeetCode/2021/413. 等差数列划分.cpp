/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/arithmetic-slices/
 * @date: 2021/8/10
 */
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        if (nums.size() < 3)
            return ans;
    	int d = nums[1] - nums[0];
        int t = 0;
    	for(int i = 2; i < nums.size(); i++)
    	{
    		if(d == nums[i] - nums[i - 1])
    		{
                t++;
    		}
            else
            {
                d = nums[i] - nums[i - 1];
                t = 0;
            }
            ans += t;
    	}
        ans += t;
        return ans;
    }
};