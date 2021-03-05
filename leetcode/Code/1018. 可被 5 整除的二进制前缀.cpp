/**
 * Author: Bao Wenjie
 * Date: 2021/3/5
 * Link: https://leetcode-cn.com/problems/binary-prefix-divisible-by-5/
 */

#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans(A.size(), false);
        int end = 0;
    	for(int i = 0; i < A.size(); i++)
    	{
            end = end * 2 + A[i];
            if (end % 5 == 0)
                ans[i] = true;
            else
                ans[i] = false;
            end %= 10;
    	}
        return ans;
    }
};