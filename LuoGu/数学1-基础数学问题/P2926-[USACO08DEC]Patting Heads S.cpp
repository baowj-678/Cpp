/**
 * @author: Bao Wenjie
 * @date: 2021/4/30
 * @link: https://www.luogu.com.cn/problem/P2926
 */

#include <cstdio>
#include <cstring>
#define scanf scanf_s

const int MAXN = 1000000 + 50;
const int MAXN_COW = 100000 + 50;
int cow_num[MAXN] = { 0 };
int cnt[MAXN] = { 0 };
int cow[MAXN_COW] = { 0 };
int main()
{
	int N, tmp, max_ = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &tmp);
		cow[i] = tmp;
		cow_num[tmp]++;
		max_ = max_ > tmp ? max_ : tmp;
	}
	int sum = 0;
	for(int i = 1; i <= max_; i++)
	{
		if(cow_num[i] == 0)
			continue;
		cnt[i] += (cow_num[i] - 1);
		for(int j = 2; j <= max_ / i; j++)
		{
			if (cow_num[i * j])
				cnt[i * j] += cow_num[i];
		}
	}
	for(int i = 0; i < N; i++)
	{
		printf("%d\n", cnt[cow[i]]);
	}
	return 0;
}