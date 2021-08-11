/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/
 * @date: 2021/8/11
 */
#include <iostream>
#include <vector>
#include <map>

using namespace::std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<map<long long, int>> M(nums.size(), map<long long, int>());
        vector<int> values(nums.size(), 0);
        int sum = 0;
    	for(int i = 1; i < nums.size(); i++)
    	{
            int s = 0;
    		for(int j = 0; j < i; j++)
    		{
                long long d = static_cast<long long>(nums[i]) - nums[j];
                if (M[i].find(d) == M[i].end())
                    M[i][d] = 0;
                M[i][d] += 1;
    			if(M[j].find(d) != M[j].end())
    			{
                    M[i][d] += M[j][d];
                    s += M[j][d];
    			}
    		}
            values[i] = s;
            sum += s;
    	}
        return sum;
    }
};

int main()
{
    vector<int> nums = { 2,4,6,8,10 };
    Solution solution;
    cout << solution.numberOfArithmeticSlices(nums);
}