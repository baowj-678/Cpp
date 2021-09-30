/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
 * @date: 2021/9/20
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            int tgt = target - nums[i];
            if (tgt <= 0)
                return ans;
            int left = i + 1, right = nums.size() - 1;
        	while(left <= right)
        	{
                int mid = (left + right) / 2;
                if (nums[mid] < tgt)
                    left = mid + 1;
                else if (nums[mid] > tgt)
                    right = mid - 1;
                else
                {
                    ans.push_back(nums[i]);
                    ans.push_back(nums[mid]);
                    return ans;
                }
        	}
        }
        return ans;
    }
};