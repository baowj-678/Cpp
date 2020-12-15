//题目描述
//有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天。
//
//输入
//有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
//
//输出
//每组数据输出一行，即日期差值
//
//样例输入 Copy
//20130101
//20130105

#include <cstdio>

int month[13][2] = { {0, 0}, 
	                 {31, 31}, 
					 {29, 28},
					 {31, 31}, 
					 {30, 30}, 
					 {31, 31}, 
					 {30, 30}, 
					 {31, 31}, 
					 {31, 31}, 
					 {30, 30}, 
					 {31, 31}, 
					 {30, 30}, 
					 {31, 31} };


// 判断闰年
bool isLeap(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main()
{
	int time1, y1, m1, d1;
	int time2, y2, m2, d2;
	while (scanf_s("%d%d", &time1, &time2) != EOF)
	{
		if (time1 > time2)
		{
			int tmp = time1;
			time1 = time2;
			time2 = tmp;
		}
		d1 = time1 % 100;
		time1 /= 100;
		m1 = time1 % 100;
		time1 /= 100;
		y1 = time1;

		d2 = time2 % 100;
		time2 /= 100;
		m2 = time2 % 100;
		time2 /= 100;
		y2 = time2;
		int days = 0;
		if (y1 != y2)
		{
			for (int i(y1 + 1); i < y2; i++)
			{
				if (isLeap(i))
					days += 366;
				else
					days += 365;
			}
			int index = 0;
			if (isLeap(y1))
				index = 1;
			days = days + month[m1][index] - d1 + 1;
			for (int i(m1 + 1); i < 13; i++)
				days += month[i][index];
			if (isLeap(y2))
				index = 1;
			else
				index = 0;
			for (int i(1); i < m2; i++)
				days += month[i][index];
			days = days + d2;
		}
		else
		{
			int index = 0;
			if (isLeap(y1))
				index = 1;
			if (m1 != m2)
			{
				days = days + month[m1][index] - d1 + 1;

				for (int i(m1 + 1); i < m2; i++)
					days += month[i][index];
				index = 1;

				days = days + d2;
			}
			else
				days = d2 - d1 + 1;
		}
		printf("%d\n", days);
	}
}
