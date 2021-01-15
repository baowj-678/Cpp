#include <iostream>
#include <string>
#include <vector>

using namespace::std;

string longestCommonPrefix(vector<string>& strs) 
{
	string s;
	vector<string>::iterator iter = strs.begin();
	if (strs.empty())
		return s;
	else
	{
		s = *iter;
		for (iter++; iter != strs.end(); iter++)
		{
			bool is_same(true);
			for (int i(0); i < s.length(); i++)
			{
				if (i < iter->length() && is_same)
				{
					if (s[i] != (*iter)[i])
					{
						is_same = false;
						s.erase(i);
					}
				}
				else if(i == iter->length() && is_same)
				{
					s.erase(i);
				}
			}
		}
		return s;
	}
	
}

int main()
{
	vector<string> strs;
	int n;
	cin >> n;
	for (int i(0); i < n; i++)
	{
		string s;
		cin >> s;
		strs.push_back(s);
	}

	cout << longestCommonPrefix(strs);


}