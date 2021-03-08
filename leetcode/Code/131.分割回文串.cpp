/**
* Author: Bao Wenjie
* Date: 2021/3/7
* Link: https://leetcode-cn.com/problems/palindrome-partitioning/
*/
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
private:
    vector<vector<char>> is_palindrome;

public:

    vector<vector<string>> partition(string s) {
        this->is_palindrome = vector<vector<char>>(s.length(), vector<char>(s.length(), -1));
        vector<vector<string>> ans;
        vector<string> sub;
        sub_partitin(s, 0, ans, sub);
        return ans;
    }

    void sub_partitin(string& s, int start, vector<vector<string>>& ans, vector<string>& sub)
    {
        if(start == s.length())
        {
            ans.push_back(sub);
            return;
        }

        for(int end = start; end < s.length(); end++)
        {
            if(can_palindrome(s, start, end))
            {
                sub.push_back(s.substr(start, end - start + 1));
                sub_partitin(s, end + 1, ans, sub);
                sub.pop_back();
            }
        }
    }

    bool can_palindrome(string& s, int start, int end)
    {
        if(this->is_palindrome[start][end] == -1)
        {
            int i = start, j = end;
            while(i < j)
            {
                if(s[i] != s[j])
                {
                    this->is_palindrome[start][end] = 0;
                    break;
                }
                i++;
                j--;
            }
            if(this->is_palindrome[start][end] == -1)
                this->is_palindrome[start][end] = 1;
        }
        return this->is_palindrome[start][end] == 1;
    }
};

int main()
{
    string s = "fvwrv";
    Solution solution;
    vector<vector<string>> ans = solution.partition(s);
    cout << ans.size() << endl;
    for(auto s : ans)
    {
        for(auto a : s)
        {
            cout << a << " ";
        }
        cout << endl;
    }
}