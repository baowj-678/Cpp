//输入两个非负 10 进制整数 A 和 B(≤2
//	​30
//	​​ −1)，输出 A + B 的 D(1 < D≤10)进制数。
//
//	输入格式：
//	输入在一行中依次给出 3 个整数 A、B 和 D。
//
//	输出格式：
//	输出 A + B 的 D 进制数。
//
//	输入样例：
//	123 456 8
//	输出样例：
//	1103

#include <cstdio>

int main()
{
	int a, b, c;
	scanf_s("%d%d%d", &a, &b, &c);
	int sum = a + b;
	int num[31];
	int i = 0;
	for (i; i < 31 && sum != 0; i++)
	{
		num[i] = sum % c;
		sum /= c;
	}
	if (i == 0)
		printf("0");
	for (int j(i - 1); j >= 0; j--)
		printf("%d", num[j]);
	printf("\n");
	return 0;
}