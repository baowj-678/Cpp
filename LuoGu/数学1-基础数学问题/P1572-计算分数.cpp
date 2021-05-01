/**
 * @author: Bao Wenjie
 * @date: 2021/5/1
 * @link: https://www.luogu.com.cn/problem/P1572
 */

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#define LL long long
#define scanf scanf_s

struct frac
{
	LL up;
	LL down;
};
struct frac vec[100];
char s[10000];

LL gcd(LL a, LL b)
{
	LL tmp;
	if(a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	while(b)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

void add(frac& a, frac& b)
{
	LL up, down, GCD;
	up = a.up * b.down + b.up * a.down;
	down = a.down * b.down;
	if(up < 0)
	{
		GCD = gcd(-up, down);
	}
	else
	{
		GCD = gcd(up, down);
	}
	a.up = up / GCD;
	a.down = down / GCD;
}

int main()
{
	scanf("%s", s, 10000);
	int n = strlen(s), k = 0, last_p = 0, key = 0;
	bool is_minus = false;
	if (isdigit(s[0]))
		last_p = -1;
	for(int i = 0; i < n; i++)
	{
		if (s[i] == '-' || s[i] == '+')
		{
			if (s[i] == '-')
			{
				is_minus = true;
			}
			else if (s[i] == '+')
			{
				is_minus = false;
			}

			if (last_p != 0)
			{
				s[i] = 0;
				LL tmp = atoll(s + last_p + 1);
				vec[k++].down = tmp;
				last_p = i;
			}
		}
		else if(s[i] == '/')
		{
			s[i] = 0;
			LL tmp = atoll(s + last_p + 1);
			if (is_minus)
				vec[k].up = -tmp;
			else
				vec[k].up = tmp;
			last_p = i;
		}
	}
	vec[k++].down = atoll(s + last_p + 1);
	frac sum = { 0, 1 };
	for(int i = 0; i < k; i++)
	{
		add(sum, vec[i]);
	}
	if (sum.down == 1)
		printf("%lld\n", sum.up);
	else
		printf("%lld/%lld\n", sum.up, sum.down);
	return 0;
}

//-23/45-90/45