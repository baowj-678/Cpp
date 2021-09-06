/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
 * @date: 2021/9/6
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0;
        int oldSize = s.size();
        for (char c : s)
            if (c == ' ')
                cnt++;
        s.resize(oldSize + 2 * cnt);
        cnt = s.size() - 1;
        oldSize--;
    	while(oldSize >= 0)
    	{
    		if(s[oldSize] == ' ')
    		{
                s[cnt--] = '0';
                s[cnt--] = '2';
                s[cnt--] = '%';
                oldSize--;
    		}
            else
            {
                s[cnt--] = s[oldSize--];
            }
    	}
        return s;
    }
};

int main()
{
    string s = "We are happy.";
    Solution solution;
    cout << solution.replaceSpace(s);
}