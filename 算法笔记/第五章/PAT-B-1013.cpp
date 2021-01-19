/**
* PAT B1013
* Author: Bao Wenjie
* Link: https://pintia.cn/problem-sets/994805260223102976/problems/994805309963354112
* Date: 2021/1/19
*/


#include<cstdio>
#define scanf scanf_s
const int maxn = 1000001;
int prime[maxn], num = 0;
bool p[maxn] = { false };
void Find_Prime(int n)
{
	for (int i = 2; i < maxn; i++)
	{
		if (p[i] == false)
		{
			prime[num++] = i;
			if (num >= n)break;
			for (int j = i + i; j < maxn; j += i)
			{
				p[j] = true;
			}
		}
	}
}

int main()
{
	int m, n, count = 0;
	scanf("%d%d", &m, &n);
	Find_Prime(n);
	for (int i = m; i <= n; i++)
	{
		printf("%d", prime[i - 1]);
		count++;
		if (count % 10 != 0 && i < n)printf(" ");
		else printf("\n");
	}
	return 0;
}
