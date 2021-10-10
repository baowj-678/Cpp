/**
 * @author: Bao Wenjie
 * @date: 2021/10/10
 * @link: https://leetcode-cn.com/problems/arranging-coins/
 */

#include <iostream>

using namespace std;


class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 1, right = 65536;
    	while(left < right)
    	{
            long long mid = (left + right) / 2;
            long long val = (mid + 1) * mid / 2;
            if (val < n)
                left = mid + 1;
            else if (val > n)
                right = mid;
            else
                return mid;
    	}
        return left - 1;
    }
};