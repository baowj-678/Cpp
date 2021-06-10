/**
 * @author: Bao Wenjie
 * @date: 2021/6/10
 * @link: https://www.luogu.com.cn/problem/P1678
 */
#include <cstdio>
#include <algorithm>
#define MAXN 100050
#define scanf scanf_s

int schools[MAXN];
int students[MAXN];

bool cmp(int a, int b)
{
	return a < b;
}

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", schools + i);
	}
	std::sort(schools, schools + m, cmp);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", students + i);
	}
	std::sort(students, students + n, cmp);
	long long sum = 0;
	int i = 0;
	for(int k = 0; k < n; k++)
	{
		while(i + 1 < m && abs(schools[i] - students[k]) >= abs(schools[i + 1] - students[k]))
		{
			i++;
		}
		sum += abs(schools[i] - students[k]);
	}
	printf("%lld\n", sum);
}