/**
 * Author: Bao Wenjie
 * Date: 2021/4/3
 * Link: https://leetcode-cn.com/problems/powx-n/
 */

#include <iostream>

using namespace::std;


class Solution {
public:
    double myPow(double x, int n) {
    	double ans = 1;
    	bool is_ops = true;
    	long long n_ = n;
    	if(n_ < 0)
    	{
    		is_ops = false;
    		n_ = -n_;
		}
		while(n_ > 0)
    	{
    		if(n_ & 0x1 == 1)
    		{
    			ans *= x;
			}
			n_ >>= 1;
			x *= x; 
		}
		if(!is_ops)
		{
			ans = 1/ans;
		}
		return ans;
    }
}; 
