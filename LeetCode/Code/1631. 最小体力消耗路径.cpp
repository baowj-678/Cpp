/**
 * Author: Bao Wenjie
 * Date: 2021/1/29
 * Link: https://leetcode-cn.com/problems/path-with-minimum-effort/
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace ::std;


struct Edge
{
    int x;
    int y;
    int delta;
};

bool compare(const Edge& a, const Edge& b)
{
    return a.delta < b.delta;
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
        int tmp_ = tmp;
        UF[tmp] = x;
        tmp = tmp_;
    }
    return x;
}

void Union(vector<int>& UF, int x, int y)
{
    int x_root = Find(UF, x);
    int y_root = Find(UF, y);
    UF[y_root] = x_root;
}

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<Edge> graph(row * col * 4 - 2 * col - 2 * row);
        vector<int> UF(row * col, 0);
        for (int i = 0; i < UF.size(); i++)
            UF[i] = i;
        int k = 0;
    	for(int i = 0; i < row; i++)
    	{
            vector<int>& height = heights[i];
    		for(int j = 0; j < col; j++)
    		{
                if (i - 1 >= 0)
                    graph[k++] = { i * col + j, i * col - col + j, abs(heights[i][j] - heights[i - 1][j])};
                if (j - 1 >= 0)
                    graph[k++] = { i * col + j, i * col + j - 1,abs(heights[i][j] - heights[i][j - 1]) };
    		}
    	}
        sort(graph.begin(), graph.end(), compare);
        int s = 0, e = row * col - 1;
    	for(Edge& p: graph)
    	{
            Union(UF, p.x, p.y);
            if (Find(UF, s) == Find(UF, e))
                return p.delta;
    	}
        return 0;
    }
};

int main()
{
    vector<vector<int>> heights = { {1, 2, 2},{3, 8, 2},{5, 3, 5} };
    Solution so;
    so.minimumEffortPath(heights);
}