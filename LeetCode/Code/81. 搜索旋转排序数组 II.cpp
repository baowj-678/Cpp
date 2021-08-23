/**
 * Author: Bao Wenjie
 * Date: 2021/4/7
 * Link: https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/
 */

#include <iostream>
using namespace::std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
    	int start = 0, left = 0, right = nums.size() - 1, mid;
    	if(nums[left] >= nums[right])
    	{
	    	while(left < right)
	    	{
	    		mid = (left + right)/2;
	    		if(nums[mid] > nums[left])
	    		{
	    			left = mid;
				}
				else if(nums[mid] < nums[right])
				{
					right = mid;
				}
				else
				{
					if(right - 1 >= 0 && nums[right-1] <= nums[right])
					{
						right--;
					}
					if(left + 1 < nums.size() && nums[left+1] >= nums[left])
					{
						left++;
					}
				}
				if(right - left <= 1)
				{
					mid = right;
					break;
				}
			}
			start = mid;
		}
		left = 0, right = nums.size() - 1;
		while(left < right)
		{
			mid = (left + right)/2;
			if(nums[(mid + start) % nums.size()] < target)
			{
				left = mid + 1;
			}
			else if(nums[(mid + start) % nums.size()] > target)
			{
				right = mid - 1;
			}
			else
			{
				return true;
			}
		}
		if(nums[(left + start) % nums.size()] == target)
			return true;
		return false;
    }
};
