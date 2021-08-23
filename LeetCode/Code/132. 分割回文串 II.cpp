/**
 * Author: Bao Wenjie
 * Date: 2021/3/8 
 * Link: https://leetcode-cn.com/problems/palindrome-partitioning-ii/
 */ 

#include <iostream>
#include <vector>
using namespace::std;


class Solution {
public:
	vector<vector<char> > g;
    int minCut(string s) {
    	this->g = vector<vector<char> >(s.length(), vector<char>(s.length(), -1));
    	vector<int> min_cut(s.length(), 0);
    	for(int i = 1; i < s.length(); i++)
    	{
    		int min_c = 100000;
    		if(is_palindrome(s, 0, i))
    		{
    			min_c = 0;
    		}
    		else
    		{
				for(int j = 0; j < i; j++)
	    		{
	    			if(is_palindrome(s, j + 1, i))
	    			{
					    min_c = min(min_c, min_cut[j] + 1);
					}
				}
			}
			min_cut[i] = min_c;
		}
		return min_cut[s.length() - 1];
    }
    
    bool is_palindrome(string& s, int start, int end)
    {
    	if(this->g[start][end] != -1)
    		return this->g[start][end] == 1;
    	
    	if(start >= end)
    	{
    		this->g[start][end] = 1;
    		return true;
    	}
    	
    	if(is_palindrome(s, start + 1, end - 1) && s[start] == s[end])
    	{
    		this->g[start][end] = 1;
    		return true;
		}
		else
		{
			this->g[start][end] = 0;
			return false;
		}
	}
};

int main()
{
	string a = "abb";
	Solution solution;
	cout << solution.minCut(a);
	return 0;
}
