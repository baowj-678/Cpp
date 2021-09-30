/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
 * @date: 2021/9/20
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>>canVisited (m, vector<bool>(n, false));
        vector<int> Fa(m * n + 1);
        for (int i = 0; i < m * n; i++)
            Fa[i] = i;
    	for(int i = 0; i < m; i++)
    	{
    		for(int j = 0; j < n; j++)
    		{
                if (numSum(i, j) <= k)
                {
                    canVisited[i][j] = true;
                    if (i > 0 && canVisited[i - 1][j])
                        unite(Fa, i * n + j, (i - 1) * n + j);
                    if (j > 0 && canVisited[i][j - 1])
                        unite(Fa, i * n + j, i * n + j - 1);
                }
    		}
    	}
        int root = find(Fa, 0);
        int ans = 0;
        for (int i = 0; i < m * n; i++)
            if (root == find(Fa, i))
                ans++;
        return ans;
    }

	int numSum(int x, int y)
    {
        int ans = 0;
    	while(x > 0)
    	{
            ans += (x % 10);
            x /= 10;
    	}
    	while(y > 0)
    	{
            ans += (y % 10);
            y /= 10;
    	}
        return ans;
    }

	int find(vector<int>& Fa, int x)
    {
        int tmp = x;
        while (Fa[tmp] != tmp)
            tmp = Fa[tmp];
    	while(Fa[x] != x)
    	{
            int t = Fa[x];
            Fa[x] = tmp;
            x = t;
    	}
        return tmp;
    }

	void unite(vector<int>& Fa, int x, int y)
    {
        int Fa_x = find(Fa, x);
        int Fa_y = find(Fa, y);
        Fa[Fa_y] = Fa_x;
    }
};