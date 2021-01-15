//给定两个数组，编写一个函数来计算它们的交集。
//
//
//
//示例 1：
//
//输入：nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//输出：[2]
//示例 2：
//
//输入：nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//输出：[9, 4]
//
//
//说明：
//
//输出结果中的每个元素一定是唯一的。
//我们可以不考虑输出结果的顺序。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/intersection-of-two-arrays
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        for (i = 0, j = 0; i < nums1.size() && j < nums2.size();)
        {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else
            {
                if (ans.empty() || ans.back() != nums1[i])
                {
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution = Solution();
    vector<int> a = { 1, 2, 3 };
    vector<int> b = { 2, 3, 4 };
    solution.intersection(a, b);
}