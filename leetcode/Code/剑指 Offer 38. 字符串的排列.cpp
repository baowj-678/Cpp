/**
 * @author: Bao Wenjie
 * @date: 2021/6/23
 * @link: https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
	vector<bool> is_visited;
	vector<string> ans;
	
	void backtarce(string& s, int i, int n, string str)
	{
		if (is_visited[i] || (i > 0 && !is_visited[i - 1] && (s[i] == s[i - 1])))
			return;
		is_visited[i] = true;
		str.push_back(s[i]);
		if (str.length() == n)
		{
			ans.push_back(str);
			is_visited[i] = false;
			str.pop_back();
			return;
		}
		for(int j = 0; j < s.length(); j++)
		{
			if(!is_visited[j])
				backtarce(s, j, n, str);
		}
		str.pop_back();
		is_visited[i] = false;
	}
	
    vector<string> permutation(string s) {
		sort(s.begin(), s.end());
		this->is_visited = vector<bool>(s.length() + 2, false);
		string str;
		for(int i = 0; i < s.length(); i++)
			backtarce(s, i, s.length(), str);
		return this->ans;
    }
};

int main()
{
	string s = "abc";
	Solution solution;
	solution.permutation(s);
}