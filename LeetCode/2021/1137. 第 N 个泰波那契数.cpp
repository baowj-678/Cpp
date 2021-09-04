/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/n-th-tribonacci-number/
 * @date: 2021/9/4
 */
#include <iostream>

class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1, d;
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else if (n == 2)
            return 1;
    	for(int i = 0; i < n - 2; i++)
    	{
            d = a + b + c;
            a = b;
            b = c;
            c = d;
    	}
        return d;
    }
};