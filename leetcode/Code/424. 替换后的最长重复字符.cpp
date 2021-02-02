/**
 * Author: Bao Wenjie
 * Date: 2021/2/2
 * Link: https://leetcode-cn.com/problems/longest-repeating-character-replacement/
 */
#include <string>
#include <iostream>

using namespace ::std;


class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26] = { 0 };
        int left = 0, right = 0;
        int max_len = 0, max_char = 0;
    	while(right < s.length())
    	{
            cnt[s[right] - 'A']++;
            max_char = max(max_char, cnt[s[right] - 'A']);
    		if(right - left + 1 - max_char > k)
    		{
                cnt[s[left++] - 'A']--;
    		}
            right++;
    	}
        return right - left;
    }
};


int main()
{
    string s = "ABAB";
    Solution so;
    so.characterReplacement(s, 2);
}