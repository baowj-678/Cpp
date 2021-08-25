/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/all-paths-from-source-to-target/
 * @date: 2021/8/25
 */
#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int G[15][15], n = graph.size();
        int flags[15];
        memset(G, 0, sizeof(G));
        memset(flags, 0, sizeof(flags));
    	for(int i = 0; i < n; i++)
    	{
    		for(int to : graph[i])
    		{
                G[i][to] = 1;
    		}
    	}
        vector<vector<int>> ans;
        vector<int> path;
        subF(ans, G, path, flags, n - 1, 0);
        return ans;
    }

	void subF(vector<vector<int>>& ans, int G[15][15], vector<int>& path,int flags[15], int tgt, int cur)
    {
        flags[cur] = 1;
        path.push_back(cur);
    	if(tgt == cur)
    	{
            ans.push_back(path);
            path.pop_back();
            flags[cur] = 0;
            return;
    	}
    	for(int i = 0; i <= tgt; i++)
    	{
    		if(G[cur][i] == 1 && flags[i] == 0)
    		{
                subF(ans, G, path, flags, tgt, i);
    		}
    	}
        path.pop_back();
        flags[cur] = 0;
    	return;
    }
};


int main()
{
    vector<vector<int>> g = { {1, 2},{3},{3},{} };
    Solution solution;
    solution.allPathsSourceTarget(g);
}