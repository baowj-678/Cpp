/**
 * @author: Bao Wenjie
 * @date: 2021/5/26
 * @link: https://www.luogu.com.cn/problem/P1255
 */

#include <cstdio>
#include <algorithm>
#define MAXN 5050
#define scanf scanf_s

int a[MAXN], b[MAXN], c[MAXN];

void hp(int* x, int* y, int* z)
{
	int len = std::max(x[MAXN - 1], y[MAXN - 1]);
	z[0] = 0;
	for(int i = 0; i < len; i++)
	{
		z[i + 1] = (x[i] + y[i] + z[i]) / 10;
		z[i] = (x[i] + y[i] + z[i]) % 10;
	}
	if (z[len] > 0)
		z[MAXN - 1] = len + 1;
	else
		z[MAXN - 1] = len;
}
int main()
{
	int n;
	int* x, * y, * z;
	scanf("%d", &n);
	if (n == 0)
		printf("0\n");
	a[0] = b[0] = a[MAXN - 1] = b[MAXN - 1] = 1;
	x = a, y = b, z = c;
	for(int i = 2; i <= n; i++)
	{
		hp(x, y, z);
		int* tmp = x;
		x = y;
		y = z;
		z = tmp;
	}
	n = y[MAXN - 1];
	for (int i = n - 1; i >= 0; i--)
		printf("%d", y[i]);
	printf("\n");
	return 0;
}