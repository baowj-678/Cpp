/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
 * @date: 2021/9/12
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int min_ = INT_MAX;
        int max_ = INT_MIN;
        min_ = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0)
                nums[i] += nums[i - 1];
            min_ = min(min_, nums[i]);
            max_ = max(max_, nums[i] - min_);
        }
        if (max_ < 0)
            return 0;
        return max_;

    }
};