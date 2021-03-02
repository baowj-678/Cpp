/**
 * Author: Bao Wenjie
 * Date: 2021/3/2
 * Link: https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
 */

#include <iostream>
#include <vector>
using namespace ::std;

class NumMatrix {
public:
    vector<vector<int>> matrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0)
            return;
        int col = matrix[0].size();
    	for(int j = 1; j < col; j++)
    	{
            matrix[0][j] += matrix[0][j - 1];
    	}
        for (int i = 1; i < row; i++)
        {
            matrix[i][0] += matrix[i - 1][0];
            for (int j = 1; j < col; j++)
            {
                matrix[i][j] += (matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1]);
            }
        }
        this->matrix = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0)
        {
            if (col1 <= 0)
                return matrix[row2][col2];
            return matrix[row2][col2] - matrix[row2][col1 - 1];
        }
        else if(col1 == 0)
        {
            if (row1 <= 0)
                return matrix[row2][col2];
            return matrix[row2][col2] - matrix[row1 - 1][col2];
        }
        else
        {
            return matrix[row2][col2] - (matrix[row2][col1 - 1] + matrix[row1 - 1][col2] - matrix[row1 - 1][col1 - 1]);
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */