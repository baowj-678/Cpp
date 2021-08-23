/**
* Author: Bao Wenjie 
* Date: 2021/3/10 
* Link: https://leetcode-cn.com/problems/basic-calculator/
*/

#include <iostream>
#include <stack>
#include <string>

using namespace::std;

class Solution {
public:
    int calculate(string s) {
    	stack<int> num_s;
    	stack<char> sym_s;
    	for(int i = 0; i < s.length(); i++)
    	{
    		char c = s[i];
    		if(c == '(')
    		{
    			sym_s.push('(');
			}
			else if(isdigit(c))
			{
				int begin = i;
				while(++i < s.length() && isdigit(s[i])){}
				int end  = i;
				int num = stoi(s.substr(begin, end - begin));
				num_s.push(num);
				i--;

				if(!sym_s.empty() && sym_s.top() != '(')
				{
					int first = num_s.top();
					num_s.pop();
					if(sym_s.top() == '*')
					{
						sym_s.pop();
						num_s.push(-first);
					}
					else if(sym_s.top() == '-')
					{
						sym_s.pop();
						int second = num_s.top();
						num_s.pop();
						num_s.push(second - first);
					}
					else if(sym_s.top() == '+')
					{
						sym_s.pop();
						int second = num_s.top();
						num_s.pop();
						num_s.push(second + first);
					}
				}
			}
			else if(c == '+')
			{
				if (!sym_s.empty() && sym_s.top() != '(')
				{
					int first = num_s.top();
					num_s.pop();
					if (sym_s.top() == '*')
					{
						sym_s.pop();
						num_s.push(-first);
					}
					else if (sym_s.top() == '-')
					{
						sym_s.pop();
						int second = num_s.top();
						num_s.pop();
						num_s.push(second - first);
					}
					else if (sym_s.top() == '+')
					{
						sym_s.pop();
						int second = num_s.top();
						num_s.pop();
						num_s.push(second + first);
					}
				}
				sym_s.push('+');
			}
			else if(c == '-')
			{
				if (!sym_s.empty() && sym_s.top() != '(')
				{
					int first = num_s.top();
					num_s.pop();
					if (sym_s.top() == '*')
					{
						sym_s.pop();
						num_s.push(-first);
					}
					else if (sym_s.top() == '-')
					{
						sym_s.pop();
						int second = num_s.top();
						num_s.pop();
						num_s.push(second - first);
					}
					else if (sym_s.top() == '+')
					{
						sym_s.pop();
						int second = num_s.top();
						num_s.pop();
						num_s.push(second + first);
					}
				}
				int j = i;
				bool is_negative = true;
				while(--j >= 0)
				{
					if(s[j] == '(' || s[j] == '-' || s[j] == '+')
					{
						break;
					}
					else if(s[j] == ' ')
					{
						continue;
					}
					else
					{
						is_negative = false;
						break;
					}
				}
				if(is_negative)
				{
					sym_s.push('*');
				}
				else
				{
					sym_s.push('-');
				}
			}
			else if(c == ')')
			{
				while(sym_s.top() != '(')
				{
					int first = num_s.top();
					num_s.pop();
					char tmp = sym_s.top();
					sym_s.pop();
					int ans;
					if(tmp == '-')
					{
						int second = num_s.top();
						num_s.pop();
						ans = second - first;
					}
					else if(tmp == '+')
					{
						int second = num_s.top();
						num_s.pop();
						ans = second + first;
					}
					else if(tmp == '*')
					{
						ans = -first;
					}
					num_s.push(ans);
				}
				sym_s.pop();
			}
			else
			{
				continue;
			}
		}
		while(!sym_s.empty())
		{
			int first = num_s.top();
			num_s.pop();
			char c = sym_s.top();
			sym_s.pop();
			if(c == '-')
			{
				int second = num_s.top();
				num_s.pop();
				first = second - first;
			}
			else if(c == '+')
			{
				int second = num_s.top();
				num_s.pop();
				first = second + first;
			}
			else if(c == '*')
			{
				first = -first;
			}
			num_s.push(first);
		}
		return num_s.top();
    }
};

int main()
{
	string s = "(7)-(0)+(4)";
	Solution solution;
	cout << solution.calculate(s);
}
