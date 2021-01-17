/**
* Author: Bao Wenjie
* Date: 2021/1/17
* Link: https://pintia.cn/problem-sets/994805260223102976/problems/994805298269634560
*/

#include <cstdio>
#define		scanf	scanf_s

int main()
{
	int cnt[10];
	for (int i(0); i < 10; i++)
	{
		scanf("%d", cnt + i);
	}
	for (int i(1); i < 10; i++)
	{
		if (cnt[i] > 0)
		{
			printf("%d", i);
			cnt[i]--;
			break;
		}
	}
	for (int i(0); i < 10; i++)
	{
		int s = cnt[i];
		for (int j(0); j < s; j++)
		{
			printf("%d", i);
		}
	}
	printf("\n");
	return  0;
}