/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/
 * @date: 2021/9/14
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool cmp(string& a, string& b)
	{
		if (a.size() > b.size())
			return true;
		else if (a.size() < b.size())
			return false;
		else
		{
			return a < b;
		}
	}
	
    string findLongestWord(string s, vector<string>& dictionary) {
		sort(dictionary.begin(), dictionary.end(), Solution::cmp);
		for(string& str : dictionary)
		{
			if (isSubStr(s, str))
				return str;
		}
		return "";
    }

	bool isSubStr(string& a, string& b)
	{
		int aP = 0, bP = 0;
		while(aP < a.size() && bP < a.size())
		{
			if(a[aP++] == b[bP])
			{
				bP++;
			}
		}
		if (bP == b.size())
			return true;
		return false;
	}
};