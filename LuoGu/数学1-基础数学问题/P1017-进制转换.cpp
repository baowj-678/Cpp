/**
 * @author Bao Wenjie
 * @date 2021/4/27
 * @link https://www.luogu.com.cn/problem/P1017
 */

#include <cstdio>
#define scanf scanf_s

using namespace ::std;
int nums[30];
char cs[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L' };
int main()
{
	int N, R, i = 0;
	scanf("%d%d", &N, &R);
	int N_ = N;
	while(N != 0)
	{
		int tmp = N % R;
		if (tmp < 0)
		{
			tmp -= R;
			N = N / R + 1;
		}
		else
		{
			N /= R;
		}
		nums[i++] = tmp;
	}
	printf("%d=", N_);
	for(--i; i >= 0; i--)
	{
		printf("%c", cs[nums[i]]);
	}
	printf("(base%d)\n", R);
}