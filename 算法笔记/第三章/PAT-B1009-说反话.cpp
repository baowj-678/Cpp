/**
* Author: Bao Wenjie
* Link: https://pintia.cn/problem-sets/994805260223102976/problems/994805314941992960
* Date: 2021/1/15
* Github: https://github.com/baowj-678
*/

#include <cstdio>

int main()
{
	int num = 0;
	char ans[90][90];
	while (scanf("%s", ans[num]) != EOF)
	{
		num++;
	}
	for (int i = num - 1; i >= 0; i--)
	{
		printf("%s", ans[i]);
		if (i > 0)printf(" ");
	}
	return 0;
}