/**
 * @author: Bao Wenjie
 * @date: 2021/5/8
 * @link: https://leetcode-cn.com/problems/find-minimum-time-to-finish-all-jobs/
 */

#include <iostream>
#include <vector>
#include <intrin.h>

using namespace::std;

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<vector<int>>dp(k, vector<int>(1 << n, INT_MAX));
        vector<int>sum(1 << n, 0);
    	for(int i = 0; i < (1 << n); i++)
    	{
            int x = 0;
    		for(int j = 0; j < n; j++)
    		{
                if (1 & (i >> j))
                    x += jobs[j];
    		}
            sum[i] = x;
    	}
    	for (int i = 0; i < (1 << n); i++)
        {
            dp[0][i] = sum[i];
        }
        for (int i = 1; i < k; i++) 
        {
            for (int j = 0; j < (1 << n); j++) 
            {
                int minn = INT_MAX;
                for (int x = j; x; x = (x - 1) & j) 
                {
                    minn = min(minn, max(dp[i - 1][j - x], sum[x]));
                }
                dp[i][j] = minn;
            }
        }
        return dp[k - 1][(1 << n) - 1];
    }
};

int main()
{
    Solution solution;
    vector<int>jobs = { 1,2,4,7,8 };
    int k = 2;
    cout << solution.minimumTimeRequired(jobs, k);
}