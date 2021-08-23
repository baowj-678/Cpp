/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/beautiful-arrangement/
 * @date: 2021/8/20
 */

#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
    int sum = 0;
    int countArrangement(int n) {
        this->sum = 0;
        vector<int> flags(n + 1, 0);
        vector<vector<int>> nums(n + 1, vector<int>());
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j < i; j++)
            {
                if(i % j == 0)
                    nums[i].push_back(j);
            }
            for(int j = i; j <= n; j++)
            {
                if(j % i == 0)
                    nums[i].push_back(j);
            }
        }
        subF(nums, flags, n, 1);
        return sum;
    }

    void subF(vector<vector<int>>& nums, vector<int> &flags, int n, int cur)
    {
        if(n < cur)
        {
            (this->sum)++;
            return;
        }
        vector<int> &vec = nums[cur];
        for(int tmp : vec)
        {
            if(flags[tmp] == 0)
            {
                flags[tmp] = 1;
                subF(nums, flags, n, cur + 1);
                flags[tmp] = 0;
            }
        }
    }
};

int main()
{
    Solution solution;
    cout << solution.countArrangement(12);
}