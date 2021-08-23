/**
 * @author: Bao Wenjie
 * @date: 2021/5/18
 * @link: https://leetcode-cn.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
 */

#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            int sum = 0;
        	for(int j = i; j < arr.size(); j++)
        	{
                sum ^= arr[j];
                if (sum == 0)
                    cnt += (j - i);
        	}
        }
        return cnt;
    }
};
