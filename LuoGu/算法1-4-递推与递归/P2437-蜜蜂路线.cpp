/**
 * @author: Bao Wenjie
 * @date: 2021/6/28
 * @link: https://www.luogu.com.cn/problem/P2437
 */
#include <cstdio>
#include <algorithm>
#define scanf scanf_s
#define MAXN 1001

int up[MAXN], up_len  = 0;
int down[MAXN], down_len = 0;
int tmp[MAXN];

int plus(int* z)
{
	int len = std::max(up_len, down_len);
	int sum = 0;
	for(int i = 0; i < len; i++)
	{
		tmp[i] = (sum + up[i] + down[i]) % 10;
		sum = (sum + up[i] + down[i]) / 10;
	}
	if(sum > 0)
	{
		tmp[len++] = sum;
	}
	for(int i = 0; i < len; i++)
	{
		z[i] = tmp[i];
	}
	return len;
}

void print(int *s, int len)
{
	for (int i = len - 1; i >= 0; i--)
		printf("%d", s[i]);
	printf("\n");
}
int main()
{
	int M, N;
	scanf("%d%d", &M, &N);
	up[0] = 1, down[0] = 1, up_len = 1, down_len = 1;
	if (M % 2 == 0)
		up[0] = 0;
	for(int i = 0; i < ((N + 1)/2 - (M + 1)/2); i++)
	{
		up_len = plus(up);
		down_len = plus(down);
	}
	if (N % 2 == 1)
		print(up, up_len);
	else
		print(down, down_len);
	return 0;
}