/**
* Topic: CSP-2018-3-URL映射
* Author: Bao Wenjie
* Email: bwj_678@qq.com
* Date: 2020/8/23
*/

#include <iostream>
#include <vector>
#include <string>

#define	INT		"<int>"
#define	STR		"<str>"
#define	PATH	"<path>"

using namespace::std;
struct Piece
{
	vector<string> elements;
	bool slash;
	string target;
};

string Match(vector<Piece>& For_Match, Piece& temp);
string isNum(string& str);
int main()
{
	// 输入
	int n, m;
	scanf_s("%d%d", &n, &m);
	vector<Piece> For_Match(n);
	vector<Piece>::iterator itor;
	string tmp;
	string sub;
	for (int i(0); i < n; i++)
	{
		cin >> tmp;
		int last = 1;
		for (int j(1); j < tmp.length(); j++)
		{
			if (tmp[j] == '/')
			{
				sub = tmp.substr(last, j - last);
				For_Match[i].elements.push_back(sub);
				last = j + 1;
			}
		}
		if (tmp[tmp.length() - 1] != '/')
		{
			For_Match[i].slash = false;
			For_Match[i].elements.push_back(tmp.substr(last, tmp.length() - last));
		}
		else
		{
			For_Match[i].slash = true;
		}
		cin >> tmp;
		For_Match[i].target = tmp;
	}
	// 匹配
	vector<string> Ans(m);
	for (int i(0); i < m; i++)
	{
		cin >> tmp;
		Piece temp;
		int last = 1;
		for (int j(1); j < tmp.length(); j++)
		{
			if (tmp[j] == '/')
			{
				temp.elements.push_back(tmp.substr(last, j - last));
				last = j + 1;
			}
		}
		if (tmp[tmp.length() - 1] != '/')
		{
			temp.slash = false;
			temp.elements.push_back(tmp.substr(last, tmp.length() - last));
		}
		else
		{
			temp.slash = true;
		}
		string ans = Match(For_Match, temp);
		if (ans == "")
			Ans[i] = "404";
		else
			Ans[i] = ans;
	}
	// 输出
	for (int i(0); i < m; i++)
	{
		cout << Ans[i] << endl;
	}
	return 0;
}

string Match(vector<Piece>& For_Match, Piece& temp)
{
	string ans = "";
	vector<Piece>::iterator itor = For_Match.begin();
	vector<string> T = temp.elements;
	vector<string> E;
	vector<string> eles;
	while (itor != For_Match.end())
	{
		E = itor->elements;
		int i;
		bool isOK = true;
		eles.clear();
		// 对每个进行匹配
		for (i = 0; i < E.size() && E.size() <= T.size(); i++)
		{
			// int
			if (E[i] == INT)
			{
				string str = isNum(T[i]);
				if (str != "")
					eles.push_back(str);
				else
				{
					isOK = false;
					break;
				}
			}
			// str
			else if (E[i] == STR)
			{
				eles.push_back(T[i]);
			}
			// path
			else if (E[i] == PATH)
			{
				if (i == E.size() - 1)
				{
					string str = "";
					for (int j(i); j < T.size() - 1; j++)
						str = str + T[j] + "/";
					str = str + T[T.size() - 1];
					if (temp.slash)
						str = str + "/";
					eles.push_back(str);
					i = T.size();
					temp.slash = itor->slash;
					break;
				}
				else
				{
					isOK = false;
					break;
				}
			}
			// string
			else
			{
				if (E[i] != T[i])
				{
					isOK = false;
					break;
				}
			}
		}

		if (i < T.size() || itor->slash != temp.slash)
			isOK = false;
		// 匹配成功
		if (isOK)
		{
			ans = itor->target;
			for (int i(0); i < eles.size(); i++)
				ans = ans + " " + eles[i];
			break;
		}
		itor++;
	}
	return ans;
}

/** 
* 判断是否是数字
*/
string isNum(string& str)
{
	int start = -1;
	for (int i(0); i < str.length(); i++)
	{
		if (isdigit(str[i]))
		{
			if (str[i] == '0' && start == i - 1)
				start = i;
		}
		else
		{
			return "";
		}
	}
	if (start == -1)
		start = 0;
	return str.substr(start, str.length() - start);
}