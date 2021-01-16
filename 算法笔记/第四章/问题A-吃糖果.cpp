/**
* Author: Bao Wenjie
* Link: http://codeup.cn/problem.php?cid=100000583&pid=0
* Date: 2021/1/16
*/

#include <cstdio>
const int N = 50;
int main()
{
	int n;
	int num[N];
	num[1] = 1;
	num[2] = 2;
	while(scanf("%d", &n) != EOF)
	{
		for (int i = 3; i <= n; i++)
		{
			num[i] = num[i - 1] + num[i - 2];
		}
		printf("%d\n", num[n]);
	}
	return 0;
}