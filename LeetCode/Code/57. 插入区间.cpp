//给出一个无重叠的 ，按照区间起始端点排序的区间列表。
//
//在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
//
//
//
//示例 1：
//
//输入：intervals = [[1, 3], [6, 9]], newInterval = [2, 5]
//输出： [[1, 5], [6, 9]]
//示例 2：
//
//输入：intervals = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], newInterval = [4, 8]
//输出： [[1, 2], [3, 10], [12, 16]]
//解释：这是因为新的区间[4, 8] 与[3, 5], [6, 7], [8, 10] 重叠。
//
//
//注意：输入类型已在 2019 年 4 月 15 日更改。请重置为默认代码定义以获取新的方法签名。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/insert-interval
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <vector>
#include <iostream>
using namespace::std;


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool is_add = false;
        for (auto i : intervals)
        {
            if (is_add)
            {
                ans.push_back(i);
                continue;
            }
            if (newInterval[0] < i[0])
            {
                if (newInterval[1] < i[0])
                {
                    ans.push_back(newInterval);
                    ans.push_back(i);
                    is_add = true;
                }
                else if (newInterval[1] < i[1])
                    newInterval[1] = i[1];
                else
                    continue;
            }
            else
            {
                if (newInterval[0] > i[1])
                    ans.push_back(i);
                else
                {
                    newInterval[0] = i[0];
                    newInterval[1] = max(newInterval[1], i[1]);
                }
            }
        }
        if (!is_add)
        {
            ans.push_back(newInterval);
        }
        return ans;
    }
};