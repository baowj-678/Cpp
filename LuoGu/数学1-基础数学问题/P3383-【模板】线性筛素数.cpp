/**
 * @author: Bao Wenjie
 * @date: 2021/6/4
 * @link: https://www.luogu.com.cn/problem/P3383
 */

#include <cstdio>
#define MAXN 12500006
#define scanf scanf_s

char nums[MAXN] = {false};
int querry[1000050] = { 0 };
void find_prime(int n)
{
	nums[0] = 0b11;
	for(int i = 2; i <= n / 2; i++)
	{
		if(((nums[i/8] >> (i % 8)) & 0b1) == 0)
		{
			for(int k = 2; k * i <= n; k++)
			{
				nums[k * i / 8] |= (0b1 << ((k * i) % 8));
			}
		}
	}
	int cnt = 0;
	for(int i = 2; i <= n && cnt < 1000050; i++)
	{
		if(((nums[i/8] >> (i%8)) & 0b1) == 0)
		{
			cnt++;
			querry[cnt] = i;
		}
	}
}

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	find_prime(n);
	for(int i = 0; i < q; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		printf("%d\n", querry[tmp]);
	}
	return 0;
}