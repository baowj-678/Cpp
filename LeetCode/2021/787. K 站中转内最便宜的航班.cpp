/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/
 * @date: 2021/8/24
 */
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INT_MAX);
        vector<int> distance_old(n, INT_MAX);
        vector<vector<int>> G(n, vector<int>(n, INT_MAX));
        distance_old[src] = 0;
        distance[src] = 0;
    	for(vector<int>& tmp : flights)
    	{
            G[tmp[0]][tmp[1]] = tmp[2];
    	}
    	for(int i = 0; i <= k; i++)
    	{
    		for(int from = 0; from < n; from++)
    		{
    			if(distance_old[from] != INT_MAX)
    			{
    				for(int to = 0; to < n; to++)
    				{
                        if (G[from][to] != INT_MAX && G[from][to] + distance_old[from] < distance[to])
                        {
                            distance[to] = distance_old[from] + G[from][to];
                        }
    				}
    			}
    		}
    		for(int j = 0; j < n; j++)
    		{
                distance_old[j] = distance[j];
    		}
    	}
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> flights = { {0, 1, 100},{1, 2, 100},{0, 2, 500} };
    solution.findCheapestPrice(3, flights, 0, 2, 1);
}