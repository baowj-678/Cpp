/**
* Author: Bao Wenjie
* Link: http://codeup.cn/problem.php?id=1818&csrf=S2UhMCEfFopNLzjMvUrmADTGg9RRugX2
* Date: 2021/1/18
*/

#include <cstdio>
#define scanf scanf_s

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		printf("%d\n", gcd(a, b));
	}
	return 0;
}