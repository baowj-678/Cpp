//给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
//
//这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
//
//示例1 :
//
//输入: pattern = "abba", str = "dog cat cat dog"
//输出 : true
//示例 2 :
//
//	输入 : pattern = "abba", str = "dog cat cat fish"
//	输出 : false
//	示例 3 :
//
//	输入 : pattern = "aaaa", str = "dog cat cat dog"
//	输出 : false
//	示例 4 :
//
//	输入 : pattern = "abba", str = "dog dog dog dog"
//	输出 : false
//	说明 :
//	你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。 
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/word-pattern
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include <string>

using namespace::std;


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string strs[26];
        int i = 0;
        for (char c :pattern)
        {
            int j = i;
            for (; j < s.size(); j++)
            {
                if (s[j] == ' ')
                {
                    break;
                }
            }
            if (j == i)
                return false;
            string tmp = s.substr(i, j - i);
            i = j + 1;
            if (strs[c - 'a'] != "")
            {
                if (strs[c - 'a'] != tmp)
                    return false;
            }
            else
            {
                strs[c - 'a'] = tmp;
            }
        }
        if (i != s.size() + 1)
            return false;
        for (int i(0); i < 26; i++)
        {
            string tmp = strs[i];
            for (int j(i + 1); j < 26; j++)
            {
                string tmp_ = strs[j];
                if (tmp == tmp_ && tmp != "")
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    string pattern = "abba";
    string s = "dog cat cat dog";
    Solution so;
    cout << so.wordPattern(pattern, s);
}