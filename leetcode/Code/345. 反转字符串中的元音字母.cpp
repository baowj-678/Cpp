/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/reverse-vowels-of-a-string/
 * @date: 2021/8/19
 */
#include<iostream>
#include<vector>
#include<string>
using namespace::std;

class Solution {
public:
    string reverseVowels(string s) {
        bool isVowel[256];
        for(int i = 0; i < 256; i++)
            isVowel[i] = false;
        isVowel['a'] = true;
        isVowel['e'] = true;
        isVowel['i'] = true;
        isVowel['o'] = true;
        isVowel['u'] = true;
        isVowel['A'] = true;
        isVowel['E'] = true;
        isVowel['I'] = true;
        isVowel['O'] = true;
        isVowel['U'] = true;

        int p_l, p_r;
        for(p_l = 0, p_r = s.length() - 1; p_l < p_r;)
        {
            if(!isVowel[s[p_l]])
            {
                p_l++;
                continue;
            }
            if(!isVowel[s[p_r]])
            {
                p_r--;
                continue;
            }
            char tmp = s[p_l];
            s[p_l] = s[p_r];
            s[p_r] = tmp;
            p_l++;
            p_r--;
        }
        return s;
    }
};

int main()
{
    Solution solution;
    string s = "leetcode";
    cout << solution.reverseVowels(s);
}