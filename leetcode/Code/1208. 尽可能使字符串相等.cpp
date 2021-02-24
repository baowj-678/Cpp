/**
 * Author: Bao Wenjie
 * Date: 2021/1/26
 * Link: https://leetcode-cn.com/problems/get-equal-substrings-within-budget/
 */


#include <iostream>
#include <string>

using namespace ::std;


class Solution {
public:

    inline int getCost(const char a, const char b)
    {
        return abs(a - b);
    }
	
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, right = 0;
        int nowCost = 0;
        bool isFind = false;
    	for(left = 0, right = 0; right < s.length(); right++)
    	{
            nowCost += getCost(s[right], t[right]);
            if (nowCost > maxCost)
            {
                nowCost -= getCost(s[left], t[left]);
                left++;
            }
            else
                isFind = true;
    	}
        if (isFind)
            return right - left;
        else
            return 0;
    }
};

int main()
{
    string a = "abcd";
    string b = "bcdf";
    Solution solution;
    solution.equalSubstring(a, b, 3);
}