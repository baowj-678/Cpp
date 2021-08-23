/**
 * Author: Bao Wenjie
 * Date: 2021/4/6
 * Link: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/
 */

#include <iostream>

using namespace::std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int i = 0, j = 0, last = 999999, cnt = 0;
    	for(j = 0; j < nums.size(); j++)
    	{
    		if(last == nums[j])
    		{
    			if(cnt < 2)
    			{
    				nums[i++] = nums[j];
    				cnt++;
				}
			}
			else
			{
				nums[i++] = nums[j];
				last = nums[j];
				cnt = 1;
			}
		}
		for(j = i; j < nums.size(); j++)
		{
			nums.pop_back();
		}
		return i;
    }
};
