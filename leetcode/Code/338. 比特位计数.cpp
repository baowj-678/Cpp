/**
 * Author: Bao Wenjie
 * Date: 2021/3/3
 * Link: https://leetcode-cn.com/problems/counting-bits/
 */

#include <iostream>
#include <vector>

using namespace ::std;


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
    	for(int i = 1, e = 1; i <= num; i++)
    	{
            if (2 * e <= i)
            {
                e *= 2;
            }
            if (e == i)
                ans[i] = 1;
            else
            {
                ans[i] = 1 + ans[i - e];
            }
    	}
        return ans;
    }
};