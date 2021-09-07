/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
 * @date: 2021/9/7
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, l, r;
    	while(left < right)
    	{
            l = (left + right) / 2;
            if (nums[l] < target)
            {
                left = l + 1;
            }
            else if (nums[l] > target)
            {
                right = l - 1;
            }
            else
                right = l;
    	}
        l = left;
        left = 0, right = nums.size() - 1;
    	while(left < right)
    	{
            r = (left + right + 1) / 2;
            if (nums[r] > target)
            {
                right = r - 1;
            }
            else if (nums[r] < target)
            {
                left = r + 1;
            }
            else
                left = r;
    	}
        r = right;
        if (nums.size() != 0 && nums[r] != target)
            return 0;
        return r - l + 1;
    }
};

int main()
{
    Solution solution;
    vector<int> vec = { 0, 0, 1, 1, 1, 4, 5, 5 };
    cout << solution.search(vec, 2);
}