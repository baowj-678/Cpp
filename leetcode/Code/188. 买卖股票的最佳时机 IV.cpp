/**
* Date: 2020/12/31
* Link: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k > prices.size() / 2)
        {
            k = prices.size() / 2;
        }
        int length = prices.size();
        int max_profit = INT32_MAX;
        vector<int> buy(length, 0);
        for (int(i) = 0; i < prices.size(); i++)
        {
            max_profit = min(prices[i], max_profit);
            buy[i] = -max_profit;
        }
        vector<int> tmp;
        vector<int> sell(length, 0);
        for (int j(0); j < k; j++)
        {
            tmp = buy;
            for (int i(1); i < prices.size(); i++)
            {
                buy[i] = max(max(sell[i - 1] - prices[i], buy[i]), buy[i-1]);
                sell[i] = max(max(tmp[i - 1] + prices[i], sell[i]), sell[i-1]);
            }
        }
        max_profit = 0;
        for (int profit : sell)
        {
            max_profit = max(max_profit, profit);
        }
        return max_profit;
    }
};


int main()
{
    Solution so;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    cout << so.maxProfit(2, prices);
}