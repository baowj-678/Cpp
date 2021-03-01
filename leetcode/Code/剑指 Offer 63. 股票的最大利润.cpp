/**
 * Author: Bao Wenjie
 * Date: 2021/1/26
 * Link: https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
 */

#include <iostream>
#include <vector>

using namespace ::std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int min_num = prices[0];
        int max_profit = 0;
    	for(int i = 0; i < prices.size(); i++)
    	{
            max_profit = max(max_profit, prices[i] - min_num);
            min_num = min(min_num, prices[i]);
    	}
        return max_profit;
    }
};