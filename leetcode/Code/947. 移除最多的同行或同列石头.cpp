/**
* Author: Bao Wenjie
* Date: 2021/1/15
* Link: https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column/
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace::std;


class Solution {
public:
    void Union(vector<int>& UF, int x, int y)
    {
        int x_root = Find(UF, x);
        int y_root = Find(UF, y);
        UF[x_root] = UF[y_root];
    }

    int Find(vector<int>& UF, int x)
    {
        int tmp = x;
        while (UF[x] != x && UF[x] != -1)
        {
            x = UF[x];
        }
        while (tmp != -1 && UF[tmp] != x)
        {
            int tmp_ = UF[tmp];
            UF[tmp] = x;
            tmp = tmp_;
        }
        return x;
    }

    int removeStones(vector<vector<int>>& stones) {
        const int L = 10001;
        vector<int> UF(2 * L + 10, -1);
        for (vector<int>& stone : stones)
        {
            Union(UF, stone[0], stone[1] + L);
        }
        unordered_map<int, int> map;
        for (int i(0); i < 2 * L; i++)
        {
            int k = UF[i];
            if (k != -1)
            {
                k = Find(UF, k);
                if (map.find(k) == map.end())
                {
                    map[k] = k;
                }
            }
        }
        return stones.size() - map.size();
    }
};

int main()
{
    vector<vector<int>> stones = { {0, 0},{0, 1},{1, 0},{1, 2},{2, 1},{2, 2} };
    Solution so;
    cout << so.removeStones(stones);
}