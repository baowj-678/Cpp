/**
* Author: Bao Wenjie
* Link: https://leetcode-cn.com/problems/fibonacci-number/
* Date: 2021/1/4
*/
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int fib(int n) {
        int first = 0, second = 1;
        for (int i(0); i < n; i++)
        {
            int tmp = first;
            first = second;
            second += tmp;
        }
        return first;
    }
};