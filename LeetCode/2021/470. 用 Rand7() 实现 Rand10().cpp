/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/implement-rand10-using-rand7/
 * @date: 2021/9/5
 */

#include <iostream>
 // The rand7() API is already defined for you.
 // int rand7();
 // @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int res;
        while (true)
        {
            res = (rand7() - 1) * 7 + rand7();
            if (res <= 40)
                break;
        }
        return res % 10 + 1;
    }
};