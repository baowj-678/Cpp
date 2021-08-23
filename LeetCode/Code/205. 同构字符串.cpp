/**
* @Date: 2020/12/27
* @Link: https://leetcode-cn.com/problems/isomorphic-strings/
*/
#include <iostream>
#include <string>

using namespace::std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int st[128];
        memset(st, -1, sizeof(int) * 128);
        int ts[128];
        memset(ts, -1, sizeof(int) * 128);
        for (int i(0); i < s.size(); i++)
        {
            if (st[s[i]] == -1)
            {
                st[s[i]] = t[i];
                if (ts[t[i]] == -1)
                    ts[t[i]] = s[i];
                else
                    return false;
            }
            if (st[s[i]] != t[i])
                return false;
        }
        return true;
    }
};

int main()
{
    string s = "add";
    string t = "egg";
    Solution so;
    cout << so.isIsomorphic(s, t);
}