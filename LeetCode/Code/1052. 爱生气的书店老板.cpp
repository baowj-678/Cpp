/**
 * Author: Bao Wenjie
 * Date: 2021/2/23
 * Link: https://leetcode-cn.com/problems/grumpy-bookstore-owner/
 */
#include <iostream>
#include <vector>

using namespace ::std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int satisfaction_num = 0;
        int improve_num = 0;
        int max_improve_num = 0;
    	for (int right = 0, left = -X + 1; right < customers.size(); right++, left++)
    	{
    		if(grumpy[right] == 0)
    		{
                satisfaction_num += customers[right];
    		}
            else
            {
                improve_num += customers[right];
            }
    		
    		if(left > 0)
    		{
                if (grumpy[left - 1] == 1)
                    improve_num -= customers[left - 1];
    		}
            max_improve_num = max(max_improve_num, improve_num);
    	}
        return satisfaction_num += max_improve_num;
    }
};