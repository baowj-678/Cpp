/**
* Auhtor: Bao Wenjie
* Link: https://pintia.cn/problem-sets/994805260223102976/problems/994805301562163200
* Date: 2021/1/17
*/

#include <cstdio>
#include <algorithm>
using namespace::std;
#define scanf scanf_s
struct MoonCake
{
	double amount;
	double profit;
	double pPera;
}cakes[1000 + 10];

bool cmp(const MoonCake& a, const MoonCake& b)
{
	return a.pPera >= b.pPera;
}

int main()
{
	int N;
	double D;
	while (scanf("%d %lf", &N, &D) != EOF)
	{
		for (int i(0); i < N; i++)
		{
			scanf("%lf", &cakes[i].amount);
		}
		for (int i(0); i < N; i++)
		{
			scanf("%lf", &cakes[i].profit);
			cakes[i].pPera = cakes[i].profit / cakes[i].amount;
		}
		sort(cakes, cakes + N, cmp);
		double profit = 0;
		for (int i(0); i < N && D > 0; i++)
		{
			if (D >= cakes[i].amount)
			{
				D -= cakes[i].amount;
				profit += cakes[i].profit;
			}
			else
			{
				profit += cakes[i].pPera * D;
				D = 0;
				break;
			}
		}
		printf("%.2f\n", profit);
	}
	return 0;
}