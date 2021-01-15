#include <iostream>
#include <string>

using namespace::std;


string convert(string s, int numRows) {
	string str;
	if (numRows == 1)
		return s;
	else
	{
		int j(0);
		while (j < s.length())
		{
			str.push_back(s[j]);
			j += 2 * (numRows - 1);
		}
		for (int i(1); i < numRows - 1; i++)
		{
			int j(i);
			while (j < s.length())
			{
				str.push_back(s[j]);
				j = j + 2 * (numRows - i - 1);
				if (j < s.length())
				{
					str.push_back(s[j]);
					j += 2 * i;
				}
			}

		}
		j = numRows - 1;
		while (j < s.length())
		{
			str.push_back(s[j]);
			j += 2 * (numRows - 1);
		}
		return str;
	}
}


int main()
{
	string s;
	int n;
	cin >> s >> n;

	cout << convert(s, n);
}

//通过，但耗时长