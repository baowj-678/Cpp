/**
* Topic: CSP-2017-12-Crontab
* Author: Bao Wenjie
* Email: bwj_678@qq.com
* Date: 2020/8/27
*/

#include <iostream>
#include <list>
using namespace::std;

struct Crontab
{
	list<short> minutes;
	list<short> hours;
	list<short> day;
	list<short> month;
	list<short> week;
	string command;
};

int PhraseToNum(string str);
int PhraseToWeek(string str);
int main()
{
	// 输入
	int n;
	long long s, t;
	cin >> n >> s >> t;
	Crontab* Vec = new Crontab[n];
	for (int i(0); i < n; i++)
	{
		string input;
		cin >> input;
		// minutes
		input.append(",");
		int last = 0, from = -1, to;
		for (int j(0); j < input.length(); j++)
		{
			if (input[j] == '*')
			{
				for (int t(0); t < 60; t++)
					Vec[i].minutes.push_back(t);
				last = j + 1;
				break;
			}
			else if (input[j] == ',')
			{
				if (from == -1)
				{
					Vec[i].minutes.push_back(atoi(input.substr(last, j - last).c_str()));
				}
				else
				{
					to = atoi(input.substr(last, j - last).c_str());
					for (int t(from); t <= to; t++)
						Vec[i].minutes.push_back(t);
					from = -1;
					to = -1;
				}
				last = j + 1;
			}
			else if (input[j] == '-')
			{
				from = atoi(input.substr(last, j - last).c_str());
				last = j + 1;
			}
		}
		// hours
		cin >> input;
		input.append(",");
		last = 0, from = -1, to = -1;
		for (int j(0); j < input.length(); j++)
		{
			if (input[j] == '*')
			{
				for (int t(0); t < 24; t++)
					Vec[i].hours.push_back(t);
				last = j + 1;
				break;
			}
			else if (input[j] == ',')
			{
				if (from == -1)
				{
					Vec[i].hours.push_back(atoi(input.substr(last, j - last).c_str()));
				}
				else
				{
					to = atoi(input.substr(last, j - last).c_str());
					for (int t(from); t <= to; t++)
						Vec[i].hours.push_back(t);
					from = -1;
					to = -1;
				}
				last = j + 1;
			}
			else if (input[j] == '-')
			{
				from = atoi(input.substr(last, j - last).c_str());
				last = j + 1;
			}
			// day
			cin >> input;
			input.append(",");
			last = 0, from = -1, to = -1;
			for (int j(0); j < input.length(); j++)
			{
				if (input[j] == '*')
				{
					Vec[i].day.push_back(-1);
					last = j + 1;
					break;
				}
				else if (input[j] == ',')
				{
					if (from == -1)
					{
						Vec[i].day.push_back(atoi(input.substr(last, j - last).c_str()));
					}
					else
					{
						to = atoi(input.substr(last, j - last).c_str());
						for (int t(from); t <= to; t++)
							Vec[i].day.push_back(t);
						from = -1;
						to = -1;
					}
					last = j + 1;
				}
				else if (input[j] == '-')
				{
					from = atoi(input.substr(last, j - last).c_str());
					last = j + 1;
				}
			}
			// month
			cin >> input;
			input.append(",");
			last = 0, from = -1, to = -1;
			for (int j(0); j < input.length(); j++)
			{
				if (input[j] == '*')
				{
					for (int t(1); t < 13; t++)
						Vec[i].month.push_back(t);
					last = j + 1;
					break;
				}
				else if (input[j] == ',')
				{
					if (isalpha(input[j - 1]))
					{
						to = PhraseToNum(input.substr(last, j - last));
					}
					else
					{
						to = atoi(input.substr(last, j - last).c_str());
					}

					if (from == -1)
					{
						Vec[i].month.push_back(to);
					}
					else
					{
						for (int t(from); t <= to; t++)
							Vec[i].month.push_back(t);
						from = -1;
						to = -1;
					}
					last = j + 1;
				}
				else if (input[j] == '-')
				{
					if (isalpha(input[j - 1]))
					{
						from = PhraseToNum(input.substr(last, j - last));
					}
					else
					{
						from = atoi(input.substr(last, j - last).c_str());
					}
					last = j + 1;
				}
			}
			// week
			cin >> input;
			input.append(",");
			last = 0, from = -1, to = -1;
			for (int j(0); j < input.length(); j++)
			{
				if (input[j] == '*')
				{
					for (int t(0); t < 6; t++)
						Vec[i].week.push_back(t);
					last = j + 1;
					break;
				}
				else if (input[j] == ',')
				{
					if (isalpha(input[j - 1]))
					{
						to = PhraseToWeek(input.substr(last, j - last));
					}
					else
					{
						to = atoi(input.substr(last, j - last).c_str());
					}

					if (from == -1)
					{
						Vec[i].hours.push_back(to);
					}
					else
					{
						for (int t(from); t <= to; t++)
							Vec[i].hours.push_back(t);
						from = -1;
						to = -1;
					}
					last = j + 1;
				}
				else if (input[j] == '-')
				{
					if (isalpha(input[j - 1]))
					{
						from = PhraseToWeek(input.substr(last, j - last));
					}
					else
					{
						from = atoi(input.substr(last, j - last).c_str());
					}
					last = j + 1;
				}
			}
		}
	}
	// 计算输出

}


/**
* 将月份小写转化成数字
*/
int PhraseToNum(string str)
{
	string Months[] = { "jan", "feb" ,"marc", "apri", "may", "june", "july", "aug", "sept", "oct", "nove", "dec"};
	for (int i(0); i < 12; i++)
	{
		if (str == Months[i])
			return i + 1;
	}
}

/**
* 将星期小写转化为数字
*/
int PhraseToWeek(string str)
{
	string Months[] = { "sun", "mon", "tue", "thur", "", "fri", "sat"};
	for (int i(0); i < 7; i++)
	{
		if (str == Months[i])
			return i + 1;
	}
}