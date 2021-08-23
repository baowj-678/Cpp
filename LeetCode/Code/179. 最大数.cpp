/**
 * Author: Bao Wenjie
 * Date: 2021/4/12
 * Link: https://leetcode-cn.com/problems/largest-number/
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace::std;

class Solution {
public:
	
	bool cmp(string &a, string& b)
	{
		return (a + b) >= (b + a);
	}
    string largestNumber(vector<int>& nums) {
    	vector<string> strs(nums.size(), "");
    	for(int i = 0; i < nums.size(); i++)
    	{
    		strs[i] = to_string(nums[i]);
		}
    	sort(strs.begin(), strs.end(), cmp);
    	string ans;
    	for(int i = 0; i < strs.size(); i++)
    	{
    		ans += strs[i];
		}
		if(ans[0] == '0')
			return "0";
		return ans;
    }
};
