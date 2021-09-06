/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
 * @date: 2021/9/6
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int left = 0, right = s.size() - 1;
        while (left < right)
            swap(s[left++], s[right--]);
        left = s.size() - n, right = s.size() - 1;
        while (left < right)
            swap(s[left++], s[right--]);
        left = 0, right = s.size() - n - 1;
        while (left < right)
            swap(s[left++], s[right--]);
        return s;
    }
};

// abc defghijk
// defghijk abc

// kjihgfed cba
