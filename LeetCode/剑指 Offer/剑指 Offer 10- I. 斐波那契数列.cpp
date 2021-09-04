/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
 * @date: 2021/9/4
 */
#include <iostream>
#include <vector>

class Solution {
public:
    int fib(int n) {
        const long long MAXN = 1e9 + 1;
        int a = 0, b = 1, c = 0;
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
    	for(int i = 0; i < n - 1; i++)
    	{
            c = (a + b) % MAXN;
            a = b;
            b = c;
    	}
        return b;
    }
};