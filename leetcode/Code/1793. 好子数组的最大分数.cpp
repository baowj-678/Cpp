/**
 * Author: Bao Wenjie
 * Date: 2021/3/26
 * Link: https://leetcode-cn.com/problems/maximum-score-of-a-good-subarray/
 */

#include <iostream>
#include <vector>
using namespace::std;


class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
    	vector<int> minNums(nums.size(), 0);
    	minNums[k] = nums[k];
    	for(int i = k - 1; i >= 0; i--)
    	{
    		minNums[i] = min(minNums[i+1], nums[i]);
		}
		for(int i = k + 1; i < nums.size(); i++)
		{
			minNums[i] = min(minNums[i-1], nums[i]);
		}
		int left = k, right = k;
		int max_value = 0;
		while(left >= 0 && right < minNums.size())
		{
			max_value = max(max_value, min(minNums[left], minNums[right]) * (right - left + 1));
			if(left == 0)
			{
				right++;
				continue;
			}
			else if(right == minNums.size() - 1)
			{
				left--;
				continue;
			}
			
			
			if(minNums[left-1] > minNums[right+1])
			{
				left--;
			}
			else
			{
				right++;
			}
		
		}
		return max_value;
    }
};

