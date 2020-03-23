#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#define MAXNUMS	10000

int nums[MAXNUMS];
void BucketSort(int* s, int n, int Max)
{
	for (int i = 0; i < n; i++)
	{
		nums[s[i]]++;
	}
	int j = 0;
	for (int i = 0; i <= Max; i++)
	{
		while (nums[i] > 0)
		{
			s[j++] = i;
			nums[i]--;
		}
	}
}

void Print(int* s, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
}

int main()
{
	memset(nums, 0, sizeof(int) * MAXNUMS);
	int n = 10000;
	int* s = (int*)malloc(sizeof(int) * n);
	clock_t begin, end;
	int Length = 3000;
	int N = 0;
	for (int i = 0; i < n; i++)
	{
		s[i] = (int)rand() % Length;
	}
	//produce a random list s
	for (int j = 1; j < 20; j++)
	{
		N = j * 500;
		begin = clock();
		for (int i = 0; i < 10000; i++)
			BucketSort(s, N, Length);
		end = clock();

		printf("%d,%f;", N+3000, (double)(end - begin) / CLOCKS_PER_SEC);
	}
}