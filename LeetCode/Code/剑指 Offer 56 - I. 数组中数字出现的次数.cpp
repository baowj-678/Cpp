/**
 * Author: Bao Wenjie
 * Date: 2021/3/22
 * Link: https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
 */

#include <iostream>
#include <vector>

using namespace::std;


class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
    	int num = 0;
    	for(int x:nums)
    	{
    		num ^= x;
		}
		int gap = 1;
		for(int i = 0; i < 16; i++)
		{
			if(gap & num)
			{
				break;
			}
			gap <<= 1;
		}
		int num_ = 0;
		num = 0;
		for(int x:nums)
		{
			if(gap & x)
			{
				num ^= x;
			}
			else
			{
				num_ ^= x;
			}
		}
		vector<int> ans = {num, num_};
		return ans;
    }
};
