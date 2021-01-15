#include <iostream>
#include <string>
using namespace::std;

string countAndSay(int n) {
	string str = "1";
	for (int i(1); i < n; i++)
	{
		string temp;
		int len = 0;
		for (int j(0); j < str.length(); j++)
		{
			len++;
			if ((j + 1 == str.length()) || (str[j] != str[j + 1]))
			{
				temp += to_string(len);
				temp += str[j];
				len = 0;
			}
		}
		str = temp;
	}
	return str;
}
int main()
{
	int n;
	cin >> n;
	cout << countAndSay(n);

}

//accepted but too slow