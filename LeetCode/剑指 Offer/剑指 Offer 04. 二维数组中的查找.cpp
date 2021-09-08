/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
 * @date: 2021/9/8
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        return subF(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, target);
    }
	
	bool subF(vector<vector<int>>& matrix, int left_n, int right_n, int left_m, int right_m, int target)
    {
    	if(left_n == right_n && left_m == right_m)
    	{
            if (matrix[left_n][left_m] == target)
                return true;
            return false;
    	}
        if (left_n > right_n)
            return false;
        if (left_m > right_m)
            return false;
        int mid_n = (left_n + right_n) / 2;
        int mid_m = (left_m + right_m) / 2;
        if (matrix[mid_n][mid_m] < target)
        {
            if (subF(matrix, mid_n + 1, right_n, mid_m + 1, right_m, target) ||
                subF(matrix, mid_n + 1, right_n, left_m, mid_m, target) ||
                subF(matrix, left_n, mid_n, mid_m + 1, right_m, target))
                return true;
        }
        else if (matrix[mid_n][mid_m] > target)
        {
            if (subF(matrix, left_n, mid_n - 1, left_m, mid_m - 1, target) ||
                subF(matrix, mid_n, right_n, left_m, mid_m - 1, target) ||
                subF(matrix, left_n, mid_n - 1, mid_m, right_m, target))
                return true;
        }
        else
            return true;
        return false;
    }
};