/**
 * @author: Bao Wenjie
 * @date: 2021/6/2
 * @link: https://www.luogu.com.cn/problem/P1143
 */
#include <cstdio>
#include <cstring>
#define MAXN 100
#define scanf scanf_s

char s[MAXN];
char t[MAXN];

char c2n(int x)
{
	if ('0' <= x && x <= '9')
		return x - '0';
	else
		return x - 'A' + 10;
}

char n2c(int x)
{
	if (0 <= x && x <= 9)
		return x + '0';
	else
		return x + 'A' - 10;
}

int main()
{
	int from, to;
	scanf("%d", &from);
	scanf("%s", s, 10);
	scanf("%d", &to);
	long long num = 0, p = 1;
	int n = strlen(s);
	for(int i = n - 1; i >= 0; i--)
	{
		s[i] = c2n(s[i]);
		num += (p * s[i]);
		p *= from;
	}
	n = 0;
	while(num > 0)
	{
		t[n++] = num % to;
		num /= to;
	}
	for(--n; n >= 0; n--)
	{
		printf("%c", n2c(t[n]));
	}
}
