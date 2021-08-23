/**
* Author: Bao Wenjie
* Link: https://leetcode-cn.com/problems/evaluate-division/
* Date: 2021/1/16
*/

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace::std;


class Solution {
public:
    double DFS(vector<vector<double>>& M, vector<int>& isVisited,int start, int end)
    {
        if (start == end)
        {
            return 1;
        }
        if (isVisited[start] == 1)
        {
            return -1;
        }
        isVisited[start] = 1;
        double ans = 0;
        vector<double>& T = M[start];
        for (int i = 0; i < T.size(); i++)
        {
            if (abs(T[i] + 1) < 1e-6)
            {
                continue;
            }
            else
            {
                ans = DFS(M, isVisited, i, end);
                if (abs(ans + 1) > 1e-6)
                {
                    isVisited[start] = 0;
                    return ans * T[i];
                }
            }
        }
        isVisited[start] = 0;
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<vector<double>> m(45, vector<double>(45, -1));
        vector<double> ans(queries.size(), 0);
        unordered_map<string, int> map;
        int i = 0;
        for (int j = 0; j < equations.size(); j++)
        {
            vector<string>& equation = equations[j];
            string& x = equation[0];
            string& y = equation[1];
            int x_idx, y_idx;
            auto tmp = map.find(x);
            if (tmp == map.end())
            {
                x_idx = i;
                map.insert(pair<string, int>{x, i++});
            }
            else
            {
                x_idx = tmp->second;
            }
            tmp = map.find(y);
            if (tmp == map.end())
            {
                y_idx = i;
                map.insert(pair<string, int> {y, i++});
            }
            else
            {
                y_idx = tmp->second;
            }
            m[x_idx][y_idx] = values[j];
            m[y_idx][x_idx] = 1/values[j];
        }
        // DFS
        vector<int> isVisited(45, 0);
        for (int i = 0; i < queries.size(); i++)
        {
            vector<string>& query = queries[i];
            auto tmp = map.find(query[0]);
            int start, end;
            double tmp_ans;
            if (tmp == map.end())
            {
                ans[i] = -1;
                continue;
            }
            else
            {
                start = tmp->second;
            }
            tmp = map.find(query[1]);
            if (tmp == map.end())
            {
                ans[i] = -1;
                continue;
            }
            else
            {
                end = tmp->second;
            }
            tmp_ans = DFS(m, isVisited, start, end);
            ans[i] = tmp_ans;
        }
        return ans;
    }
};

int main()
{
    vector<vector<string>> equations = { {"a", "b"},{"b", "c"} };
    vector<double> values = { 2.0, 3.0 };
    vector<vector<string>> queries = { {"a", "c"},{"b", "a"},{"a", "e"},{"a", "a"},{"x", "x"} };
    Solution so;
    so.calcEquation(equations, values, queries);
}