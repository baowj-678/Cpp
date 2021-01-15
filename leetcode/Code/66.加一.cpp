/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
*/

#include <iostream>
#include <vector>

using namespace::std;
vector<int> plusOne(vector<int>& digits) {
	vector<int>::iterator iter = digits.end() - 1;
	(*iter)++;
	for (iter; iter != digits.begin(); iter--)
	{
		if (*iter > 9)
		{
			*(iter - 1) += *iter / 10;
			*iter = *iter % 10;
		}
		else
		{
			break;
		}
	}
	if (*iter > 9)
	{
		*iter = *iter % 10;
		digits.insert(iter, 1);
	}
	return digits;
}
int main()
{
	vector<int> digit;
	int n;
	cout << "please input n:\n";
	cin >> n;
	for (int i(0); i < n; i++)
	{
		int x;
		cin >> x;
		digit.push_back(x);
	}
	digit = plusOne(digit);
	for (int i(0); i < digit.size(); i++)
	{
		cout << digit[i];
	}

}
//accepted