/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
 * @date: 2021/9/8
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        int cnt[256];
        memset(cnt, 0, sizeof(cnt));
        for (char c : s)
            cnt[c]++;
    	for(char c : s)
    	{
            if (cnt[c] == 1)
                return c;
    	}
        return ' ';
    }
};