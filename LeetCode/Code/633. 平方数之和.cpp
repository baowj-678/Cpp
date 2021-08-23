/**
 * @author: Bao Wenjie
 * @date: 2021/4/30
 * @link: https://leetcode-cn.com/problems/sum-of-square-numbers/
 */

#include <iostream>
using namespace ::std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 0; i < 46341; i++)
        {
            int res = c - i * i;
            if (res < 0)
                break;
            int left = i, right = 46340, mid;
        	while(left <= right)
        	{
                mid = (left + right) / 2;
        		if(mid * mid < res)
        		{
                    left = mid + 1;
        		}
                else if(mid * mid > res)
                {
                    right = mid - 1;
                }
                else
                {
                    return true;
                }
        	}
        }
        return false;
    }
};


int main()
{
    Solution solution;
    cout << solution.judgeSquareSum(2) << endl;;
}