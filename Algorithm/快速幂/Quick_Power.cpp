/**
* @Title: 快速幂
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/8/25
*/
#include <iostream>

using namespace::std;
long long Quick_Power(long long base, int index);
int main()
{
	long long base;
	int index;
	cin >> base >> index;
	cout << Quick_Power(base, index);
}

/**
* 快速幂算法
*/
long long Quick_Power(long long base, int index)
{
	long long ans = 1;
	while (index != 0)
	{
		if((index & 1) != 0)
			ans = ans * base;
		base = base * base;
		index >>= 1;
	}
	return ans;
}