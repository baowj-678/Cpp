/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/
 * @date: 2021/8/29
 */
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
    	for(int i = 1; i < arr.size(); i++)
    	{
            arr[i] += arr[i - 1];
    	}
    	for(int i = 1; i <= arr.size(); i+=2)
    	{
    		for(int j = i - 1; j < arr.size(); j++)
    		{
                if (j - i < 0)
                    sum += arr[j];
                else
                    sum += (arr[j] - arr[j - i]);
    		}
    	}
        return sum;
    }
};