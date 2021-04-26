/**
 * @author: Bao Wenjie
 * @date: 2021/4/26
 * @link: https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/
 */
#include <iostream>
#include <vector>

using namespace ::std;


class Solution {
public:
	bool canCarry(vector<int>& weights, int D, int M)
	{
        int k = 0, now_weight = 0;
		for(int i = 0; i < weights.size(); i++)
		{
            if (now_weight + weights[i] > M)
            {
                k++;
                now_weight = weights[i];
            }
            else
                now_weight += weights[i];
            if (k > D)
                return false;
		}
        if (k < D)
            return true;
        return false;
	}
	
    int shipWithinDays(vector<int>& weights, int D) {
        int left_num = 0, right_num = 0;
        for(int i = 0; i < weights.size(); i++)
        {
            left_num = max(left_num, weights[i]);
            right_num += weights[i];
        }
    	while(left_num < right_num)
    	{
            int mid_num = (left_num + right_num) / 2;
    		if(canCarry(weights, D, mid_num))
    		{
                right_num = mid_num;
    		}
            else
            {
                left_num = mid_num + 1;
            }
    	}
        return left_num;
    }
};