/**
 * Author: Bao Wenjie
 * Date: 2021/2/1
 * Link: https://pintia.cn/problem-sets/994805342720868352/problems/994805460652113920
 */

#include <stdio.h>

#define scanf scanf_s
#define printf printf_s
const int maxn = 100010;
struct Alpha
{
	char c;
	int next;
	bool is_first_visited;
}table[maxn];

int main()
{
	int begin, end, n;
	scanf("%d %d %d", &begin, &end, &n);
	for(int i = 0; i < n; i++)
	{
		int tmp1, tmp2;
		char c;
		scanf_s("%d %c %d", &tmp1, &c, 1, &tmp2);
		table[tmp1].c = c;
		table[tmp1].next = tmp2;
		table[tmp1].is_first_visited = false;
	}
	while (begin != -1)
	{
		table[begin].is_first_visited = true;
		begin = table[begin].next;
	}
	bool is_find = false;
	while(end != -1)
	{
		if (table[end].is_first_visited)
		{
			printf("%05d\n", end);
			is_find = true;
			break;
		}
		end = table[end].next;
	}
	if (!is_find)
		printf("-1\n");
}
