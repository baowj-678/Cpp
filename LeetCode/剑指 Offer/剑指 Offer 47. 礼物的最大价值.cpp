/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/valid-parenthesis-string/
 * @date: 2021/9/12
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
    	for(int j = 1; j < grid[0].size(); j++)
    	{
            grid[0][j] += grid[0][j - 1];
    	}
        for(int i = 1; i < grid.size(); i++)
        {
            grid[i][0] += grid[i - 1][0];
	        for(int j = 1; j < grid[0].size(); j++)
	        {
                grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
	        }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};