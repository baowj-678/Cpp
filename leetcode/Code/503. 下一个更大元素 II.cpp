/**
 * Author: Bao Wenjie
 * Date: 2021/1/26
 * Link: https://leetcode-cn.com/problems/next-greater-element-ii/
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace ::std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        stack<int> S1, S2;
    	for(int i = 0; i < nums.size(); i++)
    	{
    		while(!S1.empty() && S1.top() < nums[i])
    		{
                int index = S2.top();
                S2.pop();
                S1.pop();
                ans[index] = nums[i];
    		}
            S1.push(nums[i]);
            S2.push(i);
    	}
    	for(int i = 0; i < nums.size(); i++)
    	{
            while (!S1.empty() && S1.top() < nums[i])
            {
                int index = S2.top();
                S2.pop();
                S1.pop();
                ans[index] = nums[i];
            }
    	}
    	while(!S2.empty())
    	{
            ans[S2.top()] = -1;
            S2.pop();
    	}
        return ans;
    }
};
