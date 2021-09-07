/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/split-a-string-in-balanced-strings/
 * @date: 2021/9/7
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int left = 0, right = 0, cnt = 0;
    	for(char c : s)
    	{
            if (c == 'L')
                left++;
            else if (c == 'R')
                right++;
            if (left == right && left > 0)
                cnt++;
    	}
        return cnt;
    }
};