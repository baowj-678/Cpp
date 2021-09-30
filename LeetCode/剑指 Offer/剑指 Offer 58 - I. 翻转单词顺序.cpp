/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/
 * @date: 2021/9/20
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        bool hasTab = true;
    	for(j = 0; j < s.length(); j++)
    	{
    		if(s[j] == ' ')
    		{
                if (!hasTab)
                    s[i++] = s[j];
                hasTab = true;
    		}
            else
            {
                s[i++] = s[j];
                hasTab = false;
            }
    	}
        if (i == 0)
            return "";
        if (s[i - 1] == ' ')
            i--;
        int len = i;
        s.resize(len);
        j = 0, i--;
        while (j < i)
            swap(s[i--], s[j++]);
        i = 0, j = 0;
    	for(j = 0; j < len; j++)
    	{
    		if(s[j] == ' ')
    		{
                int j_ = j - 1;
                while (i < j_)
                    swap(s[i++], s[j_--]);
                i = j + 1;
    		}
    	}
        j--;
        while (i < j)
            swap(s[i++], s[j--]);
        return s;
    }
};

int main()
{
    string s = "the sky is blue";
    Solution solution;
    cout << solution.reverseWords(s);
}