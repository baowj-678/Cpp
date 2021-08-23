/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/get-maximum-in-generated-array/
 * @date: 2021/8/23
 */
#include <iostream>
using namespace::std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        int nums[105];
        nums[0] = 0, nums[1] = 1;
        int max_ = 0;
        if (n == 0)
            max_ = 0;
        else
            max_ = 1;
    	for(int i = 2; i <= n; i++)
    	{
            if (i % 2 == 0)
                nums[i] = nums[i / 2];
            else
                nums[i] = nums[i / 2] + nums[i / 2 + 1];
            max_ = max(nums[i], max_);
    	}
        return max_;
    }
};