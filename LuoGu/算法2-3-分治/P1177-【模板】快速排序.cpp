/**
 * @author: Bao Wenjie
 * @date: 2021/6/12
 * @link: https://www.luogu.com.cn/problem/P1177
 */
#include <cstdio>
#define MAXN 100050
#define scanf scanf_s

int data[MAXN];

void qsort(int begin, int end)
{
	int mid = data[(begin + end) / 2];
	int i = begin, j = end - 1;
	while(true)
	{
		while (data[i] < mid)
			i++;
		while (data[j] > mid)
			j--;
		if(i < j)
		{
			int tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
			i++;
			j--;
		}
		else
		{
			break;
		}
	}
	if (begin < j)
		qsort(begin, j);
}

int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", data + i);
	}
	qsort(0, N);
	
}