/**
* Author: Bao Wenjie
* Date: 2021/1/24
* Link: https://leetcode-cn.com/problems/maximal-square/
*/

#include <vector>
#include <iostream>
using namespace::std;


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int max_ = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == '0')
                dp[0][j] = 0;
            else
                dp[0][j] = 1;
            max_ = max(dp[0][j], max_);
        }
        for (int i = 1; i < m; i++)
        {
            if (matrix[i][0] == '0')
                dp[i][0] = 0;
            else
                dp[i][0] = 1;
            max_ = max(dp[i][0], max_);
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == '0')
                    dp[i][j] = 0;
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    max_ = max(dp[i][j], max_);
                }
            }
        }
        return max_ * max_;
    }
};

int main()
{
    vector<vector<char>> matrix = { {"1", "0", "1", "0", "0"},
                                    {"1", "0", "1", "1", "1"},
                                    {"1", "1", "1", "1", "1"},
                                    {"1", "0", "0", "1", "0"} };
    Solution so;
    so.maximalSquare(matrix);

}