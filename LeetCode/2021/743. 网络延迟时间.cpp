/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/network-delay-time/
 * @date: 2021/8/29
 */
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>reachTime(n + 1, INT_MAX);
        vector<vector<int>> G(n + 1, vector<int>(n + 1, INT_MAX));
    	for(vector<int>& time : times)
            G[time[0]][time[1]] = time[2];
        reachTime[k] = 0;
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = 1; j <= n; j++)
    		{
    			if(reachTime[j] != INT_MAX)
    			{
    				for(int k = 1; k <= n; k++)
    				{
                        if (G[j][k] != INT_MAX && G[j][k] + reachTime[j] < reachTime[k])
                            reachTime[k] = G[j][k] + reachTime[j];
    				}
    			}
    		}
    	}
        int max_ = 0;
        for (int i = 1; i <= n; i++)
            max_ = max(max_, reachTime[i]);
        if (max_ == INT_MAX)
            return -1;
        return max_;
    }
};