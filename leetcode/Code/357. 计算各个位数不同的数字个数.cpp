/**
* Link: https://leetcode-cn.com/problems/count-numbers-with-unique-digits/
* Author: Bao Wenjie
* Date: 2021/1/20
*/

#include <iostream>
using namespace::std;


class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int sum = 1;
        for (int i(0); i < n; i++)
        {
            int tmp = 9;
            for (int j = 0; j < i; j++)
            {
                tmp = tmp * (10 - j - 1);
            }
            sum += tmp;
        }
        return sum;
    }
};

int main()
{
    Solution so;
    cout << so.countNumbersWithUniqueDigits(3);
}