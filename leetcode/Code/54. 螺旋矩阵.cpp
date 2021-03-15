/**
 * Author: Bao Wenjie
 * Date: 2021/3/15
 * Link: https://leetcode-cn.com/problems/spiral-matrix/
 */

#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
    	int n = matrix.size();
    	int m = matrix[0].size();
    	int a = m * n;
    	const int right = 0, down = 1, left = 2, up = 3;
    	int x = 0, y = 0;
    	int direct = right;
    	vector<int> result(a, 0);
    	for(int i = 0; i < a; i++)
    	{
    		result[i] = matrix[x][y];
    		matrix[x][y] = -1000;
    		switch (direct)
    		{
    			case right:
    				if(y + 1 < m && matrix[x][y+1] != -1000)
    					y++;
    				else
    				{
    					direct = down;
    					x++; 
					}
					break;
				case down:
					if(x + 1 < n && matrix[x+1][y] != -1000)
						x++;
					else
					{
						direct = left;
						y--;	
					}
					break;
				case left:
					if(y - 1 >= 0 && matrix[x][y-1] != -1000)
						y--;
					else
					{
						direct = up;
						x--;
					}
					break;
				case up:
					if(x - 1 >= 0 && matrix[x-1][y] != -1000)
						x--;
					else
					{
						direct = right;
						y++;
					}
					break;
			}
		}
    	return result;
    }
};
