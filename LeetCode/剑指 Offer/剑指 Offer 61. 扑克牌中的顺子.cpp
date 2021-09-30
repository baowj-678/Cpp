/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/
 * @date: 2021/9/30
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int flags[20];
        memset(flags, 0, sizeof(flags));
        int min_ = 14, zero_n = 0;
    	for(int x : nums)
    	{
            if (x == 0)
                zero_n++;
            else
            {
                min_ = min(min_, x);
            }
    	}
    	for(int i = 0; i < 5; i++)
    	{
    		if(nums[i] != 0)
    		{
                if (flags[nums[i] - min_] == 1)
                    return false;
                flags[nums[i] - min_] = 1;
    		}
    	}
    	for(int i = 0; i < 5; i++)
    	{
            if (flags[i] == 0)
                zero_n--;
    	}
        if (zero_n == 0)
            return true;
        return false;
    }
};