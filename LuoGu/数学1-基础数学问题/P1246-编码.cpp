/**
 * @author: Bao Wenjie
 * @date: 2021/4/30
 * @link: https://www.luogu.com.cn/problem/P1246
 */

#include <cstdio>
#include <cstring>
#define scanf scanf_s
#define LL long long
using namespace ::std;

int C(int down, int up)
{
	if (up == 0)
		return 1;
	LL a = 1, b = 1;
	for(int i = 1; i <= up; i++)
	{
		a *= (down - i + 1);
		b *= i;
	}
	return int(a / b);
}

int main()
{
	char s[10];
	scanf("%s", s, 10);
	int n = strlen(s);
	if (n > 6)
	{
		printf("0\n");
		return 0;
	}
	int sum = 0;
	int last = -1;
	for(int i = 0; i < n; i++)
	{
		sum += C(26, i); // 长度小于n的个数
		int num = s[i] - 'a';
		for(int j = last + 1; j < num; j++) // 可选的个数
		{
			sum += C(25 - j, n - i - 1);
		}
		if (num <= last)
		{
			printf("0\n");
			return 0;
		}
		last = num;
	}
	printf("%d\n", sum);
}