//我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”：
//
//B.length >= 3
//存在 0 < i  < B.length - 1 使得 B[0] < B[1] < ... B[i - 1] < B[i] > B[i + 1] > ... > B[B.length - 1]
//	（注意：B 可以是 A 的任意子数组，包括整个数组 A。）
//
//	给出一个整数数组 A，返回最长 “山脉” 的长度。
//
//	如果不含有 “山脉” 则返回 0。
//
//
//
//	示例 1：
//
//	输入：[2, 1, 4, 7, 3, 2, 5]
//	输出：5
//	解释：最长的 “山脉” 是[1, 4, 7, 3, 2]，长度为 5。
//	示例 2：
//
//	输入：[2, 2, 2]
//	输出：0
//	解释：不含 “山脉”。
//
//
//	提示：
//
//	0 <= A.length <= 10000
//	0 <= A[i] <= 10000
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/longest-mountain-in-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        bool is_up = false, is_down = false;
        if (A.size() == 0)
            return 0;
        int start = 0, last_h = A[0];
        int i = 0;
        int max_length = 0;
        while (i < A.size())
        {
            int h = A[i];
            if (is_up == false && is_down == false)
            {
                if (last_h < h)
                    is_up = true;
                else
                    start = i;
                last_h = h;
            }
            else if (is_up)
            // 上山
            {
                if (last_h < h)
                // 继续上山
                {
                    last_h = h;
                }
                else if(last_h > h)
                // 下山
                {
                    is_up = false;
                    is_down = true;
                    last_h = h;
                }
                else
                // 重新开始上山
                {
                    start = i;
                    last_h = h;
                    is_up = is_down = false;
                }
            }
            else if (is_down)
            // 下山
            {
                h = A[i];
                if (last_h > h)
                // 继续下山
                {
                    last_h = h;
                }
                else if (last_h < h)
                // 下山结束
                {
                    // 统计长度
                    max_length = max(max_length, i - start);
                    // 开始新的上山
                    start = i - 1;
                    last_h = h;
                    is_up = true;
                    is_down = false;
                }
                else
                {
                    // 统计长度
                    max_length = max(max_length, i - start);
                    // 开始新的上山
                    start = i;
                    last_h = h;
                    is_up = false;
                    is_down = false;
                }
            }
            i++;
        }
        if (is_down)
            max_length = max(max_length, i - start);
        if (max_length < 3)
            return 0;
        return max_length;
    }
};


int main()
{
    vector<int> A = { 1,2,3,4,5,4,3,2,1,9,8,4 };
    Solution solution = Solution();
    cout << solution.longestMountain(A);
}