/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/longest-palindromic-subsequence/
 * @date: 2021/8/12
 */
#include <iostream>
#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        subF(dp, s, 0, s.length() - 1);
        return dp[0][s.length() - 1];
    }

	void subF(vector<vector<int>>& dp, string& s, int left, int right)
    {
        if (left > right)
            return;
        if (left == right)
        {
            dp[left][right] = 1;
            return;
        }
        int max_ = 0;
    	if(s[left] == s[right])
    	{
    		if(left + 1 > right - 1)
    		{
                max_ = 2;
    		}
            else
            {
                if (dp[left + 1][right - 1] == -1)
                    subF(dp, s, left + 1, right - 1);
                max_ = dp[left + 1][right - 1] + 2;
            }
    	}
        if (dp[left + 1][right] == -1)
            subF(dp, s, left + 1, right);
        if (dp[left][right - 1] == -1)
            subF(dp, s, left, right - 1);
        max_ = max(dp[left + 1][right], max_);
        max_ = max(dp[left][right - 1], max_);
        dp[left][right] = max_;
    }
};

int main()
{
    string s = "bbbab";
    Solution solution;
    cout << solution.longestPalindromeSubseq(s);
}