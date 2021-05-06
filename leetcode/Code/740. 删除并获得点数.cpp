/**
 * @author: Bao Wenjie
 * @date: 2021/5/6
 * @link: https://leetcode-cn.com/problems/delete-and-earn/
 */

#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int cnt[10050];
        int ans[10050];
        memset(cnt, 0, sizeof(int) * 10050);
        memset(ans, 0, sizeof(int) * 10050);
        int max_ = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cnt[nums[i]]++;
            max_ = max(max_, nums[i]);
        }
        ans[1] = cnt[1];
        for (int i = 2; i <= max_; i++)
        {
            ans[i] = max(ans[i - 1], ans[i - 2] + cnt[i] * i);
        }
        return ans[max_];
    }
};