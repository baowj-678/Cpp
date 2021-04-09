/**
 * Author: Bao Wenjie
 * Date: 2021/4/9
 * Link: https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
 */

#include <iostream>

using namespace::std;

class Solution {
public:
    int findMin(vector<int>& nums) {
    	int start = 0, left = 0, right = nums.size() - 1, mid;
    	if(nums[left] >= nums[right])
    	{
	    	while(left < right)
	    	{
				mid = (left + right) / 2;
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
					if(nums[left+1] >= nums[left])
						left++;
					if(nums[right-1] <= nums[right])
						right--;
				}
				if(right - left <= 1)
				{
					start = right;
					break;
				}
			}
		}
		return nums[right];
    }
};
