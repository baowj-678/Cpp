/**
 * Author: Bao Wenjie
 * Date: 2021/3/16
 * Link: https://leetcode-cn.com/problems/spiral-matrix-ii/
 */

#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	vector<vector<int>> result(n, vector<int>(n, -1));
    	const int right = 0, down = 1, left = 2, up = 3;
    	int direct = right;
    	int x = 0, y = 0;
    	for(int i = 1; i <= n*n; i++)
    	{
    		result[x][y] = i;
    		switch (direct)
    		{
    			case right:
    				if(y+1 < n && result[x][y+1] == -1)
    				{
    					y++;
					}
					else
					{
						x++;
						direct = down;
					}
					break;
				case down:
					if(x+1 < n && result[x+1][y] == -1)
					{
						x++;
					}
					else
					{
						y--;
						direct = left;
					}
					break;
				case left:
					if(y-1 >= 0 && result[x][y-1] == -1)
					{
						y--;
					}
					else
					{
						x--;
						direct = up;
					}
					break;
				case up:
					if(x-1 >= 0 && result[x-1][y] == -1)
					{
						x--;
					}
					else
					{
						y++;
						direct = right;
					}
					break;
			}
			
		}
		return result;
    }
};
