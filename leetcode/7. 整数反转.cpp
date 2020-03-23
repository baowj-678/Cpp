/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
*/

#include <iostream>

using namespace::std;

int reverse(int x) {
	long ten = 1;
	int temp_x = x;
	int reverseNum = 0;
	int i = 0;
	int number[10];
	while (x)
	{
		number[i] = x % 10;
		x /= 10;
		i++;
	}
	int temp_i = i;
	for (i--; i >= 0; i--)
	{
		reverseNum += ten * number[i];
		ten *= 10;
	}
	if (temp_i - 1 >= 0 && number[temp_i - 1] != reverseNum % 10)
		reverseNum = 0;
	return reverseNum;
}

int main()
{
	int x;
	cin >> x;
	while (x != -1)
	{
		cout << reverse(x) << endl;
		cin >> x;
	}
	return 0;
}

//accepted