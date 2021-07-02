/**
 * @author: Bao Wenjie
 * @date: 2021/7/1
 * @link: https://www.luogu.com.cn/problem/P1029
 */
#include <cstdio>
#define MAXN 100050
#define scanf scanf_s

bool is_prime[MAXN];
int prime[MAXN];
int cnt[MAXN];
int len = 0;
int cnt_len = 0;

void init_prime()
{
	for(int i = 0; i < 100001; i++)
	{
		is_prime[i] = true;
	}
	for(int i = 2; i < 100001; i++)
	{
		if (is_prime[i])
		{
			for (int k = 2; k * i < 100001; k++)
			{
				is_prime[k * i] = false;
			}
		}
	}
	for(int i = 2; i < 100001; i++)
	{
		if(is_prime[i])
		{
			prime[len++] = i;
		}
	}
}

int main()
{
	int x, y;
	init_prime();
	scanf("%d%d", &x, &y);
	int z = y / x;
	long long ans = 1;
	if(z * x == y)
	{
		for(int i = 0; i < len; i++)
		{
			if(z == 0)
				break;
			if(z % prime[i] == 0)
			{
				ans *= 2;
				while (z > 0 && z % prime[i] == 0)
					z /= prime[i];
			}
		}
	}
	else
	{
		ans = 0;
	}
	printf("%lld\n", ans);
}