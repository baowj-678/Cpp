#include <iostream>
#include <string>

using namespace::std;

string longestPalindrome(string s) {
	int begin = 0, end = 0;
	for (int i(0); i < (int)s.length() - 1; i++)
	{
		int j = i + 1;
		while (j < s.length())
		{
			while (s[i] != s[j] && j < s.length() - 1)
			{
				j++;
			}
			if (j - i + 1 > end - begin + 1)
			{
				bool is_palindrome = true;
				int temp_i = i, temp_j = j;
				for (; temp_i < temp_j; temp_i++, temp_j--)
				{
					if (s[temp_i] != s[temp_j])
					{
						is_palindrome = false;
						break;
					}
				}
				if (is_palindrome)
				{
					begin = i;
					end = j;
				}
			}
			j++;
		}
	}
	string longest;
	for (; begin <= end; begin++)
		longest.append(1, s[begin]);
	return longest;
}

int main()
{
	string s;
	cout << longestPalindrome(s);
	cin >> s;
	while (s!="0")
	{
		cout << longestPalindrome(s) << endl;
		cin >> s;
	}
	return 0;
}

//accepted but too slow