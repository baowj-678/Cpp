/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
 * @date: 2021/8/29
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (is_sorted(nums.begin(), nums.end())) {
            return 0;
        }
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end());
        int left = 0;
        while (nums[left] == numsSorted[left]) {
            left++;
        }
        int right = nums.size() - 1;
        while (nums[right] == numsSorted[right]) {
            right--;
        }
        return right - left + 1;
    }
};