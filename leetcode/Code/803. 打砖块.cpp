/**
* Author: Bao Wenjie
* Link: https://leetcode-cn.com/problems/bricks-falling-when-hit/
* Date: 2021/1/16
*/

#include <vector>
#include <iostream>

using namespace::std;


class Solution {
public:
    void Union(vector<int>& UF, vector<int> Size, int x, int y)
    {
        int x_root = Find(UF, x);
        int y_root = Find(UF, y);
        UF[y_root] = x_root;
        Merge(Size, x_root, y_root);
    }

    int Find(vector<int>& UF, int x)
    {
        int tmp = x;
        while (x != -1 && UF[x] != x)
        {
            x = UF[x];
        }
        if (x == -1)
            x = tmp;
        while (tmp != -1 && UF[tmp] != x)
        {
            int tmp_ = UF[tmp];
            UF[tmp] = x;
            tmp = tmp_;
        }
        return x;
    }
    void Merge(vector<int>& size, int x, int y, int width)
    {
        size[x] += size[y];
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> UF(m * n + 10, -1);
        for (vector<int>& hit : hits)
        {
            int x = hit[0], y = hit[1];
            if (grid[x][y] == 1)
                grid[x][y] = 0;
        }
        for (int i(0); i < m; i++)
        {
            for (int j(0); j < n; j++)
            {
                int x = i * n + j;
                if (grid[i][j] == 1)
                {
                    if (i > 0 && grid[i-1][j] == 1)
                    {
                        Union(UF, x, (i - 1) * n + j);
                    }
                    if (i < m - 1 && grid[i + 1][j] == 1)
                    {
                        Union(UF, x, (i + 1) * n + j);
                    }
                    if (j > 0 && grid[i][j - 1] == 1)
                    {
                        Union(UF, x, i * n + j - 1);
                    }
                    if (j < n - 1 && grid[i][j + 1] == 0)
                    {
                        Union(UF, x, i * n + j + 1);
                    }
                }
            }
        }
        int cnt = 0;
        for (int i(0); i < m; i++)
        {
            for (int j(0); j < n; j++)
            {
                int x = i * n + j;
                if (grid[i][j] == -1)
                {
                    int id = Find(UF, x);
                    if (id >= 0 && id < n)
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};