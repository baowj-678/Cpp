/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones/
 * @date: 2021/9/11
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(20, 0);
        vector<int> num(20, 0);
        int n_ = n, i = 0;
    	while(n_ > 0)
    	{
            num[i++] = n_ & 0b01;
            n_ >>= 1;
    	}
    	
    }

	int subF(int n)
    {
		int sum = 0;
	    for(int i = 0; i <= n/2; i++)
	    {
            sum += C(i, n - i);
	    }
    }

	int C(int n, int m)
    {
		int ans = 1;
    	for(int i = n; i > n - m; i++)
    	{
            ans *= i;
    	}
    	for(int i = 1; i <= m; i++)
    	{
            ans /= i;
    	}
    }
};