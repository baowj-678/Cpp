/**
 * Author: Bao Wenjie
 * Date: 2021/3/11 
 * Link: https://leetcode-cn.com/problems/basic-calculator-ii/
 */
 
#include <iostream>
#include <string>
#include <stack> 

using namespace::std;
class Solution {
public:
	void doIt(stack <long long>& num_s, char sym)
	{
		long long first, second;
		switch (sym)
		{
			case '-':
				first = num_s.top();
				num_s.pop();
				second = num_s.top();
				num_s.pop();
				first = second - first;
				num_s.push(first);
				break;
			case '+':
				first = num_s.top();
				num_s.pop();
				second = num_s.top();
				num_s.pop();
				first = second + first;
				num_s.push(first);
				break;
			case '*':
				first = num_s.top();
				num_s.pop();
				second = num_s.top();
				num_s.pop();
				first = first * second;
				num_s.push(first);
				break;
			case '/':
				first = num_s.top();
				num_s.pop();
				second = num_s.top();
				num_s.pop();
				first = second / first;
				num_s.push(first);
				break;
			default:
				return;
		}
	}
	
    int calculate(string s) {
    	stack<long long> num_s;
    	stack<char> sym_s;
    	for(int i = 0; i < s.length(); i++)
    	{
    		if(s[i] == '-')
    		{
    			int j = i;
    			bool is_negative = true;
    			while(--j >= 0)
    			{
    				if(isdigit(s[j]))
    				{
    					is_negative = false;
    					break;
    				}
    				else if(s[j] == ' ')
    					continue;
    				else
    				{
    					is_negative = true;
    					break;
					}
				}
				if(is_negative)
				{
					sym_s.push(-1);
				}
				else
				{
	    			while(!sym_s.empty())
	    			{
	    				doIt(num_s, sym_s.top());
	    				sym_s.pop();
					}
					sym_s.push('-');
				}
			}
			else if(s[i] == '+')
			{
				while(!sym_s.empty())
				{
					doIt(num_s, sym_s.top());
					sym_s.pop();
				}
				sym_s.push('+');
			}
			else if(s[i] == '*')
			{
				while(!sym_s.empty() && (sym_s.top() == '*' || sym_s.top() == '/'))
				{
					doIt(num_s, sym_s.top());
					sym_s.pop();
				}
				sym_s.push('*');
			}
			else if(s[i] == '/')
			{
				while(!sym_s.empty() && (sym_s.top() == '*' || sym_s.top() == '/'))
				{
					doIt(num_s, sym_s.top());
					sym_s.pop();
				}
				sym_s.push('/');
			}
			else if(isdigit(s[i]))
			{
				long long num = s[i] - '0';
				int j = i;
				while(++j < s.length() && isdigit(s[j]))
				{
					num = num * 10 + s[j] - '0';
				}
				if(!sym_s.empty() && sym_s.top() == -1)
				{
					sym_s.pop();
					num_s.push(-num);
				}
				else
				{
					num_s.push(num);
				}
				i = --j;
			}
			else
			{
				continue;
			}
		}
		while(!sym_s.empty())
		{
			doIt(num_s, sym_s.top());
			sym_s.pop(); 
		}
		return num_s.top();
    }
};




int main()
{
	string s = "0";
	Solution solution;
	cout << solution.calculate(s);
}
