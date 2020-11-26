//给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
//
//如果数组元素个数小于 2，则返回 0。
//
//示例 1 :
//
//输入: [3, 6, 9, 1]
//输出 : 3
//解释 : 排序后的数组是[1, 3, 6, 9], 其中相邻元素(3, 6) 和(6, 9) 之间都存在最大差值 3。
//示例 2 :
//
//输入: [10]
//输出 : 0
//解释 : 数组元素个数小于 2，因此返回 0。
//说明 :
//
//你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
//请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/maximum-gap
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <vector>
#include <algorithm>
#include <iostream>

using namespace::std;


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
        {
            return 0;
        }
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int d = max(1, (maxVal - minVal) / (n - 1));
        int bucketSize = (maxVal - minVal) / d + 1;
        vector<pair<int, int>> bucket(bucketSize, { -1, -1 });
        for (int i = 0; i < n; i++)
        {
            int idx = (nums[i] - minVal) / d;
            if (bucket[idx].first == -1)
            {
                bucket[idx].first = bucket[idx].second = nums[i];
            }
            else
            {
                bucket[idx].first = min(bucket[idx].first, nums[i]);
                bucket[idx].second = max(bucket[idx].second, nums[i]);
            }
        }
        int ret = 0;
        int prev = -1;
        for (int i(0); i < bucketSize; i++)
        {
            if (bucket[i].first == -1) continue;
            if (prev != -1)
            {
                ret = max(ret, bucket[i].first - bucket[prev].second);
            }
            prev = i;
        }
        return ret;
    }
};


int main()
{
    int nums[] = { 100, 3, 2, 1 };
    vector<int> nums_(nums, nums + 4);
    Solution so;
    cout << so.maximumGap(nums_);
}
