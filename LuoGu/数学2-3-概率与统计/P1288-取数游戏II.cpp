/**
 * @author: Bao Wenjie
 * @date: 2021/6/26
 * @link: https://www.luogu.com.cn/problem/P1288
 */

#include <cstdio>
#include <algorithm>
#define MAXN 100
#define scanf scanf_s

int edges[MAXN];
int main()
{
	int N;
	scanf("%d", &N);
	int left = 100, right = 100;
	for(int i = 0; i < N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if(tmp == 0)
		{
			left = std::min(i, left);
			right = std::min(right, N - 1 - i);
		}
	}
	if (left % 2 == 1 || right % 2 == 1)
		printf("YES\n");
	else
		printf("NO\n");
}