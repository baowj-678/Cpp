/**
* Author: Bao Wenjie
* Link: https://leetcode-cn.com/problems/min-cost-to-connect-all-points/
* Date: 2021/1/19
*/


#include <vector>
#include <algorithm>
using namespace::std;


bool cmp(vector<int>& a, vector<int>& b)
{
    return a[0] < b[0];
}

class Solution {
public:
    bool Union(vector<int>& UF, vector<int>& sz, int x, int y)
    {
        int x_root = Find(UF, x);
        int y_root = Find(UF, y);
        if (x_root == y_root)
            return false;
        UF[y_root] = x_root;
        sz[x_root] += sz[y_root];
        return true;
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

    inline int calcDistance(vector<int>& p1, vector<int>& p2)
    {
        return (abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]));
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<int> UF(points.size(), -1);
        vector<int> sz(points.size(), 1);
        vector<vector<int>> distance(points.size() * points.size(), vector<int>(3, 0));
        int width = points.size();
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = 0; j < points.size(); j++)
            {
                distance[i * width + j][0] = calcDistance(points[i], points[j]);
                distance[i * width + j][1] = i;
                distance[i * width + j][2] = j;
            }
        }
        sort(distance.begin(), distance.end(), cmp);
        int sum = 0;
        for (vector<int>& vec : distance)
        {
            if (Union(UF, sz, vec[1], vec[2]))
            {
                sum += vec[0];
                if (sz[vec[1]] == points.size())
                    return sum;
            }
        }
        return sum;
    }
};


int main()
{
    vector<vector<int>> points = { {0, 0},{2, 2},{3, 10},{5, 2},{7, 0} };
    Solution so;
    so.minCostConnectPoints(points);
}