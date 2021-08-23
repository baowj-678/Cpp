/**
 * Author: Bao Wenjie
 * Date: 2021/3/30
 * Link: https://leetcode-cn.com/problems/search-a-2d-matrix/
 */

#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	int n = matrix.size();
    	int m = matrix[0].size();
    	int start = 0, end = n * m - 1, mid = 0;
    	int x, y, tmp;
    	while(start <= end)
    	{
    		mid = (start + end) / 2;
    		x = mid / m;
    		y = mid - x * m;
    		tmp = matrix[x][y];
    		if(target < tmp)
    		{
    			end = mid + 1;
			}
			else if(target > tmp)
			{
				start = mid + 1;
			}
			else
			{
				return true;
			}
		}
		return false;
    }
};
