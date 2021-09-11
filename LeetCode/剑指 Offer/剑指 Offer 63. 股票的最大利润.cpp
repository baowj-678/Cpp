/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
 * @date: 2021/9/11
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_ = INT_MAX;
        int max_ = 0;
    	for(int x : prices)
    	{
            min_ = min(min_, x);
            max_ = max(max_, x - min_);
    	}
        return max_;
    }
};