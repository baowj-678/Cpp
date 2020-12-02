//给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。
//
//若可行，输出任意可行的结果。若不可行，返回空字符串。
//
//示例 1 :
//
//输入: S = "aab"
//输出 : "aba"
//示例 2 :
//
//	输入 : S = "aaab"
//	输出 : ""
//	注意 :
//
//	S 只包含小写字母并且长度在[1, 500]区间内。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/reorganize-string
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include <string>

using namespace::std;
class Solution {
public:
    string reorganizeString(string S) {
        int cnt[26];
        memset(cnt, 0, sizeof(int)*26);
        for (char c : S)
        {
            cnt[c - 'a']++;
        }
        int length = S.size();
        if (length % 2 == 0)
            length = length / 2;
        else
            length = length / 2 + 1;
        int j = 0, i = 0;
        for (int t = 0; t < 26; t++)
        {
            if (cnt[t] > length)
                return "";
            else if (cnt[t] == length)
            {
                for (; i < S.size(); i += 2)
                {
                    if (cnt[t] == 0)
                        break;
                    S[i] = t + 'a';
                    cnt[t]--;
                }
            }

        }
        for (; i < S.size(); i += 2)
        {
            while (j < 26 && cnt[j] <= 0)
                j++;
            S[i] = j + 'a';
            cnt[j]--;
        }
        for (int i(1); i < S.size(); i += 2)
        {
            while (j < 26 && cnt[j] <= 0)
                j++;
            S[i] = j + 'a';
            cnt[j]--;
        }
        return S;
    }
};

int main()
{
    Solution so;
    cout << so.reorganizeString("vvvlo");
}