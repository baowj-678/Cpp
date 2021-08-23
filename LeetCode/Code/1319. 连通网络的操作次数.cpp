/**
* Link: https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected/
* Author: Bao Wenjie
* Date: 2021/1/23
*/

#include <vector>
#include <iostream>
#include <unordered_set>
using namespace::std;


class Solution {
public:
    void Union(vector<int>& UF, int x, int y)
    {
        int x_root = Find(UF, x);
        int y_root = Find(UF, y);
        UF[y_root] = x_root;
    }

    int Find(vector<int>& UF, int x)
    {
        int tmp = x;
        while (UF[x] != x)
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;
        vector<int> UF(n, 0);
        for (int i(0); i < n; i++)
            UF[i] = i;
        for (vector<int>& connect : connections)
        {
            Union(UF, connect[0], connect[1]);
        }
        unordered_set<int> set;
        for (int i = 0; i < n; i++)
        {
            int x = Find(UF, i);
            if (set.find(x) == set.end())
                set.insert(x);
        }
        return set.size() - 1;
    }
};