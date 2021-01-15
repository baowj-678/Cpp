/**
* Author: Bao Wenjie
* Date: 2021/1/14
* Github: https://github.com/baowj-678
* Source: https://leetcode-cn.com/problems/redundant-connection/
*/

#include <iostream>
#include <vector>

using namespace::std;


class Solution {
public:
    bool Union(vector<int> &UF, int x, int y)
    {
        int y_root = Find(UF, y);
        int x_root = Find(UF, x);
        UF[y_root] = x_root;
        if (x_root == y_root)
            return false;
        return true;
    }

    int Find(vector<int> &UF, int x)
    {
        if (UF[x] == -1)
        {
            UF[x] = x;
        }
        int tmp = x;
        while (UF[x] != -1 && UF[x] != x)
        {
            x = UF[x];
        }
        while (UF[tmp] != x)
        {
            int tmp_ = UF[tmp];
            UF[tmp] = x;
            tmp = tmp_;
        }
        return x;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> points(edges.size() + 10, -1);
        for (vector<int>& edge : edges)
        {
            if (!Union(points, edge[0], edge[1]))
            {
                return edge;
            }
        }
        return vector<int>();
    }
};

int main()
{
    vector<vector<int>> edges = { {1, 2},{1, 3},{2, 3} };
    Solution so;
    so.findRedundantConnection(edges);
}