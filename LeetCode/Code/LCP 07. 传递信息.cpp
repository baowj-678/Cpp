/**
 * @author: Bao Wenjie
 * @date: 2021/7/1
 * @link: https://leetcode-cn.com/problems/chuan-di-xin-xi/
 */
#include <iostream>
#include <vector>
using namespace::std;


class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        int dp[10][12];
        vector<vector<int>> from(n, vector<int>());
    	for(vector<int> &x : relation)
    	{
            from[x[1]].push_back(x[0]);
    	}
        for (int i = 0; i < n; i++)
            dp[0][i] = 0;
        dp[0][0] = 1;
    	for(int i = 1; i <= k; i++)
    	{
    		for(int j = 0; j < n; j++)
    		{
                dp[i][j] = 0;
    			for(int m : from[j])
    			{
                    dp[i][j] += dp[i - 1][m];
    			}
    		}
    	}
        return dp[k][n - 1];
    }
};