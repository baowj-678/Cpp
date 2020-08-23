/**
* Topic: CSP-2018-3-Åö×²µÄÐ¡Çò
* Author: Bao Wenjie
* Email: bwj_678@qq.com
* Date: 2020/8/22
*/
#include <iostream>
#define	MAXN	100+10
using namespace::std;
int Posi[MAXN];
int Direct[MAXN];

int main()
{
	int n, L, t;
	scanf_s("%d%d%d", &n, &L, &t);
	for (int i(0); i < n; i++)
	{
		scanf_s("%d", Posi + i);
		Direct[i] = 1;
	}
	for (int i(1); i <= t; i++)
	{
		Posi[0] += Direct[0];
		if (Posi[0] == 0)
			Direct[0] = 1;
		for (int j(1); j < n; j++)
		{
			Posi[j] += Direct[j];
			if (Posi[j] == Posi[j - 1])
			{
				Direct[j - 1] *= -1;
				Direct[j] *= -1;
			}
		}
		if (Posi[n - 1] == L)
			Direct[n - 1] = -1;
	}
	for (int i(0); i < n; i++)
	{
		printf("%d ", Posi[i]);
	}
	printf("\n");
}