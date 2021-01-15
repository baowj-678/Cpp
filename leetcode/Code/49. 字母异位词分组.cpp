//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
//
//示例 :
//
//输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出 :
//	[
//		["ate", "eat", "tea"],
//		["nat", "tan"],
//		["bat"]
//	]
//说明：
//
//所有输入均为小写字母。
//不考虑答案输出的顺序。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/group-anagrams
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace::std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ans;
        for (string str : strs)
        {
            string s = str;
            sort(s.begin(), s.end());
            if (map.find(s) != map.end())
            {
                map[s].push_back(str);
            }
            else
            {
                vector<string> tmp = { str };
                map.insert(pair<string, vector<string>>(s, tmp));
            }
        }
        for (auto pa : map)
        {
            ans.push_back(pa.second);
        }
        return ans;
    }
};

int main()
{
    vector<int> tmp = { 1 };
    vector<int>& a = tmp;
    
    vector<vector<int>> A;
    A.push_back(a);
    a.push_back(9);

}