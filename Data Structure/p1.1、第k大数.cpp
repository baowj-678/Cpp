#include <stdio.h>
#include <malloc.h>

using namespace::std;

int TopK(int *number, int n, int k)
{
	int* topk = (int*)malloc(sizeof(int) * k);
	int i = 0;
	for (i = 0; i < k; i++)
	{
		topk[i] = number[i];
	}
	for (i = k -1; i > 0; i--)
	{
		int j;
		for (j = 0; j < i; j++)
		{
			if (topk[j] > topk[i])
			{
				int temp = topk[i];
				topk[i] = topk[j];
				topk[j] = temp;
			}
		}
	}
	for (i = k; i < n; i++)
	{
		int j;
		for (j = 0; j < k; j++)
		{
			if (topk[j] < number[i])
			{
				if ((j < k - 1) && topk[j + 1] < number[i])
					topk[j] = topk[j + 1];
				else
				{
					topk[j] = number[i];
					break;
				}
			}
		}
	}
	return topk[0];
}

int main()
{
	int n;
	printf_s("please input n:\n");
	scanf_s("%d", &n);
	int* number = (int*)malloc(sizeof(int) * n);
	while (n)
	{
		printf_s("plaese input k:\n");
		int k;
		scanf_s("%d", &k);
		int i = 0;
		for (i; i < n; i++)
		{
			scanf_s("%d", &number[i]);
		}
		printf_s("Top %d:%d\n", k, TopK(number, n, k));
		printf_s("please input n:\n");
		scanf_s("%d", &n);
	}
	return 0;
}