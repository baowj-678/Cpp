/**
 * @author: Bao Wenjie
 * @date: 2021/6/9
 * @link: https://www.luogu.com.cn/problem/P5019
 */
#include <cstdio>
#define MAXN 100050
#define scanf scanf_s

int deep[MAXN];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", deep + i);
	}
	int cnt = 0, last_deep = 0;
	for(int i = 0; i < n; i++)
	{
		if(deep[i] >= last_deep)
		{
			cnt += (deep[i] - last_deep);
		}
		last_deep = deep[i];
	}
	printf("%d\n", cnt);
}