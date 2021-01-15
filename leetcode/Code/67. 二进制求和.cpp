/*
给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
*/
#include <iostream>
#include <string>

using namespace::std;

string addBinary(string a, string b) {
	int i, j;
	string& s = a.size() > b.size() ? a : b;
	string& l = a.size() <= b.size() ? a : b;
	for (i = s.size() - 1, j = l.size() - 1; i > 0; i--, j--)
	{
		if (j >= 0)
			s[i] += (l[j] - '0');
		if (s[i] > '1')
		{
			s[i - 1] += (s[i] - '0') / 2;
			s[i] = (s[i] - '0') % 2 + '0';
		}
	}
	if (j == 0)
		s[i] += (l[j] - '0');
	if (s[i] > '1')
	{
		s.insert(0, 1, ((s[i] - '0') / 2 + '0'));
		s[i + 1] = (s[i + 1] - '0') % 2 + '0';
	}
	return s;
}

int main()
{
	string s, l;
	cin >> s;
	cin >> l;
	cout<<addBinary(s, l)<<endl;
}
//accepted
