/**
* @author: Bao Wenjie
* @date: 2021/5/10
* @link: https://www.luogu.com.cn/problem/P1020
*/

#include <iostream>
#include <algorithm>
#define scanf scanf_s
#define INT_MIN     (-2147483647 - 1)
#define INT_MAX       2147483647

const int MAXN = 100010;
int a[MAXN];
int up[MAXN];
int down[MAXN];
int main()
{
	int n = -1;
	// while (scanf("%d", &a[++n]) != EOF) {}
	for (int i = 0; i < 8; i++)
		scanf("%d", &a[++n]);
	int i_down = 0, i_up = 0;
	down[0] = a[0];
	up[0] = a[0];
	for (int j = 1; j < n; j++)
	{
		if (down[i_down] >= a[j])
		{
			down[++i_down] = a[j];
		}
		else
		{
			int p = std::upper_bound(down, down + i_down + 1, a[j], std::greater<int>()) - down;
			down[p] = a[j];
		}

		if (up[i_up] < a[j])
		{
			up[++i_up] = a[j];
		}
		else
		{
			int p = std::lower_bound(up, up + i_up + 1, a[j], std::greater<int>()) - up;
			up[p] = a[j];
		}
		
	}
	printf("%d\n%d\n", i_down + 1, i_up + 1);
	return 0;
}