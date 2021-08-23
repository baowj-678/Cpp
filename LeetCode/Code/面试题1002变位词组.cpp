/**
 * @author: Bao Wenjie
 * @date: 2021/7/18
 * @link: https://leetcode-cn.com/problems/group-anagrams-lcci/
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace::std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> string2index;
        vector<vector<string>> ans;
        for(string s:strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            if(string2index.find(tmp) == string2index.end())
            {
                ans.push_back(vector<string>());
                ans[ans.size() - 1].push_back(s);
                string2index[tmp] = ans.size() - 1;
            }
            else
            {
                ans[string2index[tmp]].push_back(s);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
    string a, b;
    a = "jfgf";
    a.c_str();
}