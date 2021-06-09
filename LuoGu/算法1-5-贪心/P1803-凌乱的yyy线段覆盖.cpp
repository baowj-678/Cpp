/**
 * @author: Bao Wenjie
 * @date: 2021/6/7
 * @link: https://www.luogu.com.cn/problem/P1803
 */

#include <cstdio>
#include <algorithm>
#define MAXN 1000050
#define scanf scanf_s

typedef struct time
{
	int begin;
	int end;
}time;

bool cmp(time& a, time& b)
{
	if (a.end == b.end)
		return a.begin < b.begin;
	return a.end < b.end;
}

time times[MAXN];


int main()
{
	int n, a, b;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &(times[i].begin), &(times[i].end));
	}
	std::sort(times, times + n, cmp);
	int now_t = 0, cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(times[i].begin >= now_t)
		{
			cnt++;
			now_t = times[i].end;
		}
	}
	printf("%d\n", cnt);
}