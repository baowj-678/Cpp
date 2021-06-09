/**
 * @author: Bao Wenjie
 * @date: 2021/6/7
 * @link: https://www.luogu.com.cn/problem/P1223
 */

#include <cstdio>
#include <algorithm>
#define MAXN 1010
#define scanf scanf_s

typedef struct time
{
	int t;
	int i;
}time;

bool cmp(time& a, time& b)
{
	return a.t < b.t;
}

time times[MAXN];

int main()
{
	int n, tmp;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);
		times[i].t = tmp;
		times[i].i = i;
	}
	std::sort(times + 1, times + n + 1, cmp);
	double total = 0;
	for(int i = 1; i <= n; i++)
	{
		total += (n - i) * times[i].t;
		printf("%d ", times[i].i);
	}
	printf("\n%.2f\n", total / n);
}


