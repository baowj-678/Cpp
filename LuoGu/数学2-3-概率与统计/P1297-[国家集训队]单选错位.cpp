/**
 * @author: Bao Wenjie
 * @date: 2021/6/26
 * @link: https://www.luogu.com.cn/problem/P1297
 */

#include <cstdio>
#include <algorithm>
#define MAXN 100000010
#define scanf scanf_s

int a[MAXN];

int main()
{
	int n, A, B, C;
	// for C/C++
	scanf("%d%d%d%d%d", &n, &A, &B, &C, a + 1);
	for (int i = 2; i <= n; i++)
		a[i] = ((long long)a[i - 1] * A + B) % 100000001;
	for (int i = 1; i <= n; i++)
	{
		a[i] = a[i] % C + 1;
		// printf("%d ", a[i]);
	}
	double sum = 0;
	for(int i = 2; i <= n; i++)
	{
		sum += (1.0 / std::max(a[i - 1], a[i]));
	}
	if(n > 2)
	{
		sum += (1.0 / std::max(a[1], a[n]));
	}
	printf("%.3lf\n", sum);
}