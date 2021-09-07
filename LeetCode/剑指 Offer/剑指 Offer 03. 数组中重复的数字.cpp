/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
 * @date: 2021/9/7
 */
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int> flags(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            flags[nums[i]]++;
            if (flags[nums[i]] > 1)
                return nums[i];
        }
        return -1;
    }
};