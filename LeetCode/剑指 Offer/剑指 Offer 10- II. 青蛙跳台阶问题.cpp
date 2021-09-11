/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
 * @date: 2021/9/11
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numWays(int n) {
        vector<int> nums(105, 0);
        const int maxn = 1000000007;
        nums[1] = 1, nums[2] = 2;
    	for(int i = 3; i <= n; i++)
    	{
            nums[i] = (nums[i - 1] + nums[i - 2]) % maxn;
    	}
        return nums[n];
    }
};