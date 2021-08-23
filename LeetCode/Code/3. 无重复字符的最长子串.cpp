/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

#include <iostream>
#include <string>

using namespace::std;

int lengthOfLongestSubstring(string s) 
{
	int longest = 0;
	int left = 0;
	for (int right = 0; right < s.length(); right++)
	{
		bool isUnrepeat = true;
		for (int j(left); j < right; j++)
		{
			if (s[j] == s[right])
			{
				left = j + 1;
				isUnrepeat = false;
				break;
			}
		}
		if (isUnrepeat && right - left + 1 > longest)
		{
			longest = right - left + 1;
		}
	}
	return longest;
}

int main()
{
	string s;
	cin >> s;
	cout << lengthOfLongestSubstring(s);

}

//accepted