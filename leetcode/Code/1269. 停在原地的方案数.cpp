/**
 * @author: Bao Wenjie
 * @date: 2021/5/13
 * @link: https://leetcode-cn.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
 */

#include <iostream>
#include <vector>

using namespace::std;
class Solution {
public:
    const int MAXN = 1e9 + 7;
    int numWays(int steps, int arrLen) {
        arrLen = min(steps, arrLen);
        vector<vector<int>>dp(steps + 1, vector<int>(arrLen, 0));
        dp[0][0] = 1;
        arrLen--;
    	for(int i = 1; i <= steps; i++)
    	{
    		for(int j = 1; j < arrLen; j++)
    		{
                dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j])%MAXN + dp[i - 1][j + 1]) % MAXN;
    		}
            if (arrLen >= 1)
            {
                dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MAXN;
                dp[i][arrLen] = (dp[i - 1][arrLen] + dp[i - 1][arrLen - 1]) % MAXN;
            }
            else
            {
                dp[i][0] = dp[i - 1][0];
            }
    	}
        return (dp[steps][0]);
    }
};

int main()
{
    Solution solution;
    solution.numWays(1, 1);
}