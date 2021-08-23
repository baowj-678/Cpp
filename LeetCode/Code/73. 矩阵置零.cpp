/**
 * Author: Bao Wenjie
 * Date: 2021/3/21
 * Link: https://leetcode-cn.com/problems/set-matrix-zeroes/
 */
#include <iostream>

using namespace::std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	int m = matrix[0].size();
    	int col0 = 0, row0 = 0;
        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        		if(matrix[i][j] == 0)
        		{
        			matrix[i][0] = 0;
        			matrix[0][j] = 0;
        			if(i == 0)
        				row0 = 1;
        			if(j == 0)
        				col0 = 1;
				}
			}
		}
		for(int i = 1; i < n; i++)
		{
			if(matrix[i][0] == 0)
			{
				for(int j = 1; j < m; j++)
				{
					matrix[i][j] = 0;
				}
			}
		}
		for(int j = 1; j < m; j++)
		{
			if(matrix[0][j] == 0)
			{
				for(int i = 1; i < n; i++)
				{
					matrix[i][j] = 0;
				}
			}
		}
		if(row0 == 1)
		{
			for(int j = 0; j < m; j++)
			{
				matrix[0][j] = 0;
			}
		}
		if(col0 == 1)
		{
			for(int i = 0; i < n; i++)
			{
				matrix[i][0] = 0;
			}
		}
		return matrix;
    }
};
