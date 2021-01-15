#include <iostream>
#include <string>
using namespace::std;
/*
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指由字母组成，但不包含任何空格的字符串。

示例:

输入: "Hello World"
输出: 5
*/
int lengthOfLastWord(string s) {
	int length = 0;
	cout << s.size();
	for (int i(s.size() - 1); i>= 0; i--)
	{
		if (s[i] != ' ')
			length++;
		else if (length)
			break;
	}
	return length;
}


int main()
{
	string s;
	getline(cin, s);
	cout << lengthOfLastWord(s);
	return 0;
}

//accepted