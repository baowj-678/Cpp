//题目描述
//读入一串字符，判断是否是回文串。“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。
//
//输入
//一行字符串，长度不超过255。
//
//输出
//如果是回文串，输出“YES”，否则输出“NO”。
//
//样例输入 Copy
//12321
//样例输出 Copy
//YES

#include <cstdio>
#include <cstring>


int main()
{
	char str[260];
	scanf_s("%s", str);
	int length = strlen(str);
	for (int i(0), j(length - 1); i <= j; i++, j--)
	{
		if (str[i] != str[j])
		{
			printf("NO\n");
			break;
		}
	}
	printf("YES\n");
	return 0;
}