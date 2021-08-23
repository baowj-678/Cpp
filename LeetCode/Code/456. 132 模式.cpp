/**
 * Author: Bao Wenjie
 * Date: 2021/3/24
 * Link: https://leetcode-cn.com/problems/132-pattern/
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace::std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int n = nums.size(), right = -0x3f3f3f3f;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < right) return true;
            while (!s.empty() && nums[i] > s.top()) {
                right = max(right, s.top());
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};