/**
* Author: Bao Wenjie
* Link: https://pintia.cn/problem-sets/994805260223102976/problems/994805282389999616
* Date: 2021/1/17
*/

#include <cstdio>
#include <cstring>
#define scanf scanf_s
#define MAXN 100000 + 100
char str[MAXN];
int leftP[MAXN] = { 0 };

int main()
{
	scanf("%s", str);
	int len = strlen(str);
	for (int i(0); i < len; i++)
	{
		if (i > 0)
			leftP[i] = leftP[i - 1];
		if (str[i] == 'P')
			leftP[i]++;
	}
	int ans = 0, rightT = 0;
	for (int i(len - 1); i > 0; i--)
	{
		if (str[i] == 'A')
			ans = (ans + leftP[i - 1] * rightT) % 1000000007;
		else if (str[i] == 'T')
			rightT++;
	}
	printf("%d\n", ans);
	return 0;
}