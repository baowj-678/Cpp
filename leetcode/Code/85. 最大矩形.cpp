/**
* @Date: 2020/12/27
* @Link: https://leetcode-cn.com/problems/maximal-rectangle/
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace::std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        vector<int> dp(matrix[0].size(), 0);
        int area = 0;
        for (vector<char>line : matrix)
        {
            for (int i(0); i < dp.size(); i++)
            {
                if (line[i] == '0')
                    dp[i] = 0;
                else
                    dp[i] += 1;
            }
            area = max(this->largestRectangleArea(dp), area);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int> up_stk;
        int area = 0;
        for (int i(0); i < heights.size(); i++)
        {
            int height = heights[i];
            while (!up_stk.empty() && heights[up_stk.top()] > height)
            {
                int last = up_stk.top();
                up_stk.pop();
                if (up_stk.empty())
                    area = max(area, i * heights[last]);
                else
                    area = max(area, (i - up_stk.top() - 1) * heights[last]);
            }
            up_stk.push(i);
        }
        while (!up_stk.empty())
        {
            int last = up_stk.top();
            up_stk.pop();
            if (up_stk.empty())
                area = max(area, (int)heights.size() * heights[last]);
            else
                area = max(area, ((int)heights.size() - up_stk.top() - 1) * heights[last]);
        }
        return area;
    }
};