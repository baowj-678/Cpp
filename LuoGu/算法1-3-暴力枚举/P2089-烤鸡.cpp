/**
 * @author: Bao Wenjie
 * @date: 2021/6/10
 * @link: https://www.luogu.com.cn/problem/P2089
 */
#include <cstdio>
#define MAXN 60000
#define scanf scanf_s

char ans[MAXN][10];
int n = 0;

char tmp[10];
void find(int i, int total)
{
	if(i == 9)
	{
		if(1 <= total && total <= 3)
		{
			tmp[9] = total;
			for (int j = 0; j < 10; j++)
				ans[n][j] = tmp[j];
			n++;
		}
		else
		{
			return;
		}
	}
	if (total < 1)
		return;
	for(int j = 1; j <= 3 && j < total; j++)
	{
		tmp[i] = j;
		find(i + 1, total - j);
	}
}

int main()
{
	int total;
	scanf("%d", &total);
	find(0, total);
	printf("%d\n", n);
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
}