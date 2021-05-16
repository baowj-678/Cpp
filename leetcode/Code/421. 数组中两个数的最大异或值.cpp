/**
 * @author: Bao Wenjie
 * @date: 2021/5/16
 * @link: https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/
 */

#include <iostream>
#include <vector>
#include <set>

using namespace::std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        set<int> s;
        int x = 0;
        for (int i = 30; i >= 0; i--)
        {
            s.clear();
            for (int num : nums)
            {
                s.insert(num >> i);
            }
            int x_next = (x << 1) + 1;
            bool is_find = false;
        	for(int num : nums)
        	{
        		if(s.find(x_next ^ (num >> i)) != s.end())
        		{
                    is_find = true;
        			break;
        		}
        	}
            if (is_find)
                x = x_next;
            else
                x = x << 1;
        }
        return x;
    }
};