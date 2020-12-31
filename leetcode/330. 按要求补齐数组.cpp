/**
* Date: 2020/12/31
* Link: https://leetcode-cn.com/problems/patching-array/
*/
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        long long x = 1;
        int length = nums.size(), index = 0;
        while (x <= n) {
            if (index < length && nums[index] <= x) {
                x += nums[index];
                index++;
            }
            else {
                x *= 2;
                patches++;
            }
        }
        return patches;
    }
};

int main()
{
    Solution so;
    vector<int> a = { 0 };
    cout << so.minPatches(a, 6);
}