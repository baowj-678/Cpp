/**
 * @author: Bao Wenjie
 * @date: 2021/6/10
 * @link: https://leetcode-cn.com/problems/coin-change-2/
 */

#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int change(int amount, vector<int>& coins)
	{
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
    	for(int coin : coins)
    	{
    		for(int x = coin; x <= amount; x ++)
    		{
                dp[x] += dp[x - coin];
    		}
    	}
        return dp[amount];
    }
	
};