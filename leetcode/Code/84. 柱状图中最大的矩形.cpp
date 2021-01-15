/**
* Date: 2020/12/27
* Link: https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
*/
#include <vector>
#include <iostream>
#include <stack>
using namespace::std;



class Solution {
public:
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


int main()
{
    Solution so;
    vector<int> a = { 2,1,5,6,2,3 };
    cout << so.largestRectangleArea(a);
}