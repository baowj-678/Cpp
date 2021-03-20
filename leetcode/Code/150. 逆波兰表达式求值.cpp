/**
 * Author: Bao Wenjie
 * Date: 2021/3/20
 * Link: https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace::std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	stack<int> Nums;
    	for(string& s : tokens)
    	{
    		if(isdigit(s[0]))
    		{
    			int n = atoi(s.c_str());
    			Nums.push(n);
			}
			else
			{
				int a = Nums.top();
				Nums.pop();
				int b = Nums.top();
				Nums.pop();
				int c = 0;
				switch (s[0])
				{
					case '+':
						c = a + b;
						break;
					case '-':
						c = b - a;
						break;
					case '*':
						c = b * a;
						break;
					case '/':
						c = b / a;
						break;
				}
				Nums.push(c);
			}
		}
		return Nums.top();
    }
};
