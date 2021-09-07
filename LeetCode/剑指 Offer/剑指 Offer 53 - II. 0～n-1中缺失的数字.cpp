/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/
 * @date: 2021/9/7
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
    	while(left < right)
    	{
            int mid = (left + right) / 2;
            if (nums[mid] == mid)
                left = mid + 1;
            else
                right = mid;
    	}
        if (nums[left] == nums[left])
            return nums.size();
        return left;
    }
};