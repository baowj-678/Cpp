/**
 * Author: Bao Wenjie
 * Date: 2021/2/19
 * Link: https://leetcode-cn.com/problems/max-consecutive-ones-iii/
 */

#include <vector>
#include <iostream>

using namespace ::std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0, right = 0;
        int sum_one = 0;
    	for(right = 0; right < A.size(); right++)
    	{
    		if(A[right] == 1)
    		{
                sum_one++;
    		}
    		if(right - left + 1 > sum_one + K)
    		{
    			if(A[left] == 1)
    			{
                    sum_one--;
    			}
                left++;
    		}
    	}
        return (right - left + 1);
    }
};

int main()
{
    vector<int>A = { 1,1,1,0,0,0,1,1,1,1,0 };
    Solution solution;
    solution.longestOnes(A, 2);
}