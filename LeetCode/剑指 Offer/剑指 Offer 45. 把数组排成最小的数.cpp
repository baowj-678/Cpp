/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
 * @date: 2021/9/30
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string& a, string& b)
{
	return (a + b < b + a);
}

class Solution {
public:
	
    string minNumber(vector<int>& nums) {
		string strs[101];
		string ans = "";
		int i = 0;
		for(int x : nums)
		{
			strs[i++] = to_string(x);
		}
		sort(strs, strs + i, cmp);
		int j = 0;
		for(int k = 0; k < i; k++)
		{
			ans += strs[k];
		}
		return ans;
    }
};


int main()
{
	vector<int> vec = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	Solution solution;
	solution.minNumber(vec);
}
/*

824 82482

8248 824
824 8248

*/