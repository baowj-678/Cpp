#include <iostream>
#include <string>

using namespace::std;

int romanToInt(string s) 
{
	int  first, second, sum = 0;
	int len = s.length();
	s.push_back('O');

	for (int i(1); i <= len; i++)
	{
		switch (s[i - 1])
		{
		case 'I':
			first = 1;
			break;
		case 'V':
			first = 5;
			break;
		case 'X':
			first = 10;
			break;
		case 'L':
			first = 50;
			break;
		case 'C':
			first = 100;
			break;
		case 'D':
			first = 500;
			break;
		case 'M':
			first = 1000;
			break;
		default:
			first = 0;
			break;
		}

		switch (s[i])
		{
		case 'I':
			second = 1;
			break;
		case 'V':
			second = 5;
			break;
		case 'X':
			second = 10;
			break;
		case 'L':
			second = 50;
			break;
		case 'C':
			second = 100;
			break;
		case 'D':
			second = 500;
			break;
		case 'M':
			second = 1000;
			break;
		default:
			second = 0;
			break;
		}

		if (first < second)
		{
			sum += (second - first);
			i++;
		}
		else
		{
			sum += first;
		}
	}
	return sum;
}

int main()
{
	string s;
	cin >> s;
	cout << romanToInt(s) << endl;
}

//Í¨¹ý
