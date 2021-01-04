/**
* Date: 2021/1/2
* Link: https://leetcode-cn.com/problems/sliding-window-maximum/
*/

#include <queue>
#include <vector>

using namespace::std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans(nums.size() - k + 1, 0);
        priority_queue<int> heap;
        int j = 0;
        for (int i(0);i<nums.size();i++)
        {
            heap.push(nums[i]);
            if (i >= k - 1)
            {
                ans[j] = heap.top();
            }
            
        }
    }
};