#include <stdio.h>
#include <time.h>

int squareSum(int n)
{
	int sum = 0;
	for (++n; n > 0; n--)
		sum += n * n;
	return sum;
}

int main()
{
	clock_t start_time, end_time;
	int n, m;
	scanf_s("%d%d", &n, &m);
	start_time = clock();
	for (int i(0); i < n; i++)
		squareSum(m);
	end_time = clock();
	printf_s("%f", (float)(end_time - start_time) / CLOCKS_PER_SEC);
}