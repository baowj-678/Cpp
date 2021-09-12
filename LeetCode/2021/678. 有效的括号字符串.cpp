/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/valid-parenthesis-string/
 * @date: 2021/9/12
 */
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left_s;
        stack<int> star_s;
    	for(int i = 0; i < s.length(); i++)
    	{
            char c = s[i];
            if (c == '(')
            {
                left_s.push(i);
            }
            else if(c == ')')
            {
                if (!left_s.empty())
                    left_s.pop();
                else if (!star_s.empty())
                    star_s.pop();
                else
                    return false;
            }
            else
            {
                star_s.push(i);
            }
    	}
    	while(!left_s.empty() && !star_s.empty())
    	{
            int left_index = left_s.top();
            left_s.pop();
            int star_index = star_s.top();
            star_s.pop();
            if (left_index > star_index)
                return false;
    	}
        return left_s.empty();
    }
};