/**
* Date: 2021/1/1
* Link: https://leetcode-cn.com/problems/can-place-flowers/
*/
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(), 0);
        int cnt = 0;
        for (int i(0); i < flowerbed.size() && n >0; i++)
        {
            if (flowerbed[i] == 0)
                cnt++;
            else
                cnt = 0;
            if (cnt >= 3)
            {
                n--;
                cnt = 1;
            }
        }
        return n <= 0;
    }
};