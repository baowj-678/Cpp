/**
 * Author: Bao Wenjie
 * Date: 2021/3/11
 */

#include <cstdio>
#include <set>
#define scanf scanf_s
#define printf printf_s


using namespace ::std;

const int maxn = 110;
int UF[maxn] = { -1 };

int Find(int x)
{
	int tmp = x;
	while(x != UF[x])
	{
		x = UF[x];
	}
	while(tmp != x)
	{
		int f = UF[tmp];
		UF[tmp] = x;
		tmp = f;
	}
	return x;
}

void Union(int x, int y)
{
	int f_x = Find(x);
	int f_y = Find(y);
	UF[f_y] = f_x;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		UF[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		Union(a, b);
	}
	set<int> s;
	for(int i = 0; i < n; i++)
	{
		s.insert(Find(i));
	}
	printf("%d\n", s.size());
}