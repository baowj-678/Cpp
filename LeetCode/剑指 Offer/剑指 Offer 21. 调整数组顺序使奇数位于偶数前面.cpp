/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
 * @date: 2021/9/19
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int ii = nums.size() - 1, i = nums.size() - 1;
    	while(ii >= 0)
    	{
            while (ii >= 0 && nums[ii] % 2 == 0)
                ii--;
    		if(ii == -1)
                break;
            i = ii - 1;
            while (i >= 0 && nums[i] % 2 == 1)
                i--;
    		if(i == -1)
                break;
            swap(nums[i], nums[ii]);
            ii--;
    	}
        return nums;
    }
};