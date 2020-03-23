#include <iostream>
#include <queue>
#include <stdio.h>
#include <time.h>
#define BUCKET_NUM	20

using namespace::std;

queue<int> bucket[BUCKET_NUM];
void RadixSort(int* nums, int n, int maxLength, int radix)
{
	//遍历桶
	int B = 1;
	for (int i = 0; i < maxLength; i++)
	{
		//遍历数组
		for (int j = 0; j < n; j++)
		{
			int temp = nums[j]/B;
			bucket[temp % radix].push(nums[j]);
		}
		int k = 0;
		for (int j(0); j < radix; j++)
		{
			while (!bucket[j].empty())
			{
				nums[k++] = bucket[j].front();
				bucket[j].pop();
			}
		}
		B *= radix;
	}
	return;
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
	int n;
	int nums[100];
	printf("Please input n\n");
	scanf_s("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", nums + i);
	}
	RadixSort(nums, n, 3, 10);
	for (i = 0; i < n; i++)
		printf("%d ", nums[i]);
}