/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/valid-triangle-number/
 * @date: 2021/8/31
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
    	for(int i = 0; i + 2 < nums.size(); i++)
    	{
    		for(int j = i + 1; j + 1 < nums.size(); j++)
    		{
                int left = j + 1, right = nums.size() - 1;
    			if(nums[left] >= nums[i] + nums[j])
                    continue;
    			while(left < right)
    			{
                    int mid = (left + right + 1) / 2;
                    if (nums[mid] >= nums[i] + nums[j])
                        right = mid - 1;
                    else
                        left = mid;
    			}
                ans += (left - j);
    		}
    	}
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> vec = { 513, 154, 216, 535 };
    solution.triangleNumber(vec);
}