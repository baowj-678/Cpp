/**
* Author: Bao Wenjie
* Link: https://pintia.cn/problem-sets/994805260223102976/problems/994805302786899968
* Date: 2021/1/18
*/

#include <cstdio>
#include <algorithm>
#define scanf scanf_s

using namespace::std;


void to_array(int n, char num[])
{
	int i = 0;
	while (n > 0)
	{
		num[i++] = n % 10;
		n /= 10;
	}
}

int to_int_decrease(char num[], int n)
{
	int ans = 0;
	for (int i(0); i < n; i++)
	{
		ans = ans * 10 + num[i];
	}
	return ans;
}

int to_int_up(char num[], int n)
{
	int ans = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		ans = ans * 10 + num[i];
	}
	return ans;
}

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	char nums[10];
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int sub = -1;
		while (sub != 0 && sub != 6174)
		{
			to_array(n, nums);
			sort(nums, nums + 4, cmp);
			int x = to_int_decrease(nums, 4);
			int y = to_int_up(nums, 4);
			sub = x - y;
			printf("%04d - %04d = %04d\n", x, y, sub);
			n = sub;
		}
	}
	return 0;
}