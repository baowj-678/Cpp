/**
 * Author: Bao Wenjie
 * Date: 2021/1/29
 * Link: http://codeup.cn/problem.php?cid=100000605&pid=0
 */

#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <map>

using namespace ::std;

struct node
{
	double num;
	char op;
	bool flag;
};

map<char, int> op;
stack<node> s;
// 中缀表达式 -> 后缀表达式
void Change(string& str, queue<node>& Q)
{
	double num;
	node tmp;
	for(int i = 0; i < str.length();)
	{
		if(isdigit(str[i]))
		{
			tmp.flag = true;
			tmp.num = str[i++] - '0';
			while(i < str.length() && isdigit(str[i]))
			{
				tmp.num = tmp.num * 10 + (str[i] - '0');
				i++;
			}
			Q.push(tmp);
		}
		else
		{
			tmp.flag = false;
			while(!s.empty() && op[str[i]] <= op[s.top().op])
			{
				Q.push(s.top());
				s.pop();
			}
			tmp.op = str[i];
			s.push(tmp);
			i++;
		}
	}
	while(!s.empty())
	{
		Q.push(s.top());
		s.pop();
	}
}

double Cal(queue<node>& Q)
{
	double tmp1, tmp2;
	node cur, tmp;
	while(!Q.empty())
	{
		cur = Q.front();
		Q.pop();
		if (cur.flag == true)
			s.push(cur);
		else
		{
			tmp2 = s.top().num;
			s.pop();
			tmp1 = s.top().num;
			s.pop();
			tmp.flag = true;
			if (cur.op == '+')
				tmp.num = tmp1 + tmp2;
			else if (cur.op == '-')
				tmp.num = tmp1 - tmp2;
			else if (cur.op == '*')
				tmp.num = tmp1 * tmp2;
			else
				tmp.num = tmp1 / tmp2;
			s.push(tmp);
		}
	}
	return s.top().num;
}

int main()
{
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;
	string str;
	queue<node> Q;
	while(getline(cin, str), str != "0")
	{
		for(string::iterator it = str.end() - 1; it != str.begin(); it--)
		{
			if (*it == ' ')
				str.erase(it);
		}
		while (!s.empty())
			s.pop();
		while (!Q.empty())
			Q.pop();
		Change(str, Q);
		printf("%.2f\n", Cal(Q));
	}
	return 0;
}