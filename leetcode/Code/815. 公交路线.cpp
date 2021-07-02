/**
 * @author: Bao Wenjie
 * @date: 2021/6/28
 * @link: https://leetcode-cn.com/problems/bus-routes/
 */
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace::std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        vector<int> M[1000010];
        bool is_visited[1000010];
        bool is_visited_route[550];
    	for(int i = 0; i < routes.size(); i++)
    	{
            is_visited_route[i] = false;
    		for(int x:routes[i])
    		{
                M[x].push_back(i);
                is_visited[x] = false;
    		}
    	}
        queue<int> Q;
        if (source != target)
            Q.push(source);
        else
            return 0;
        Q.push(-1);
        int cnt = 0;
    	while(Q.size() > 1)
    	{
            int x = Q.front();
            Q.pop();
    		if(x == -1)
    		{
                cnt++;
                Q.push(-1);
    			continue;
    		}
            if (x == target)
                return cnt;
    		for(int k:M[x])
    		{
    			if(!is_visited_route[k])
    			{
    				for(int i:routes[k])
    				{
                        if (!is_visited[i])
                        {
                            is_visited[i] = true;
                            Q.push(i);
                        }
    				}
                    is_visited_route[k] = true;
    			}
    		}
    	}
        return -1;
    }
};