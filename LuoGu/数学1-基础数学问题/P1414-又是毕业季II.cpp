/**
 * @author: Bao Wenjie
 * @date: 2021/5/3
 * @link: https://www.luogu.com.cn/problem/P1414
 */

#include <cstdio>
#include <cmath>
#include <algorithm>
#define scanf scanf_s

const int MAXN = 1000100;
int cnt[MAXN] = { 0 };
int ans[10050] = { 0 };

void getFactor(int x)
{
	for(int i = 1; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			cnt[i]++;
			if (i != x / i)
				cnt[x / i]++;
		}
	}
	return;
}

int main()
{
	int N, x, max_ = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &x);
		max_ = max_ > x ? max_ : x;
		getFactor(x);
	}
	for(int i = 1; i <= max_; i++)
	{
		ans[cnt[i]] = std::max(ans[cnt[i]], i);
	}
	max_ = 0;
	for(int i = N; i > 0; i--)
	{
		max_ = ans[i] = std::max(ans[i], max_);
	}
	for (int i = 1; i <= N; i++)
		printf("%d\n", ans[i]);
	return 0;
}