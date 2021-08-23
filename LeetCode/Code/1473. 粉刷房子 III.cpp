/**
 * @author: Bao Wenjie
 * @date: 2021/5/4
 * @link: https://leetcode-cn.com/problems/paint-house-iii/
 */
#include <iostream>
#include <vector>

using namespace::std;
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const int MAXN = 999999;
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(target, MAXN)));
        if(houses[0] != 0)
        {
            dp[0][houses[0]][0] = 0;
        }
        else
        {
	        for(int j = 0; j < n; j++)
	        {
                dp[0][j][0] = cost[0][j];
	        }
        }
    	for(int i = 1; i < m; i++)
    	{
    		if(houses[i] != 0)
    		{
                int j = houses[i];
                for (int k = 1; k < target; k++)
                {
                    int min_ = MAXN;
                    if (k != 0)
                    {
                        for (int l = 0; l < n; l++)
                        {
                            if (l != j)
                                min_ = min(dp[i - 1][l][k - 1], min_);
                        }
                    }
                    min_ = min(dp[i - 1][j][k], min_);
                    dp[i][j][k] = min_;
                }
    		}
            else
            {
	            for(int j = 0; j < n; j++)
	            {
		            for(int k = 0; k < target; k++)
		            {
                        int min_ = MAXN;
                        if (k != 0)
                        {
                            for (int l = 0; l < n; l++)
                            {
                                if (l != j)
                                    min_ = min(dp[i - 1][l][k - 1] + cost[i][l], min_);
                            }
                        }
                        min_ = min(dp[i - 1][j][k] + cost[i][j], min_);
                        dp[i][j][k] = min_;
		            }
	            }
            }
    	}
        int min_ = 0;
        for (int j = 0; j < n; j++)
            min_ = min(min_, dp[m - 1][j][target - 1]);
        return min_ >= MAXN ? -1 : min_;
    }
};

int main()
{
    Solution solution;
    vector<int> houses = { 0,0,0,0,0 };
    vector<vector<int>>cost = { {1, 10},{10, 1},{10, 1},{1, 10},{5, 1} };
    int m = 5, n = 2, target = 3;
    cout << solution.minCost(houses, cost, m, n, target);
}