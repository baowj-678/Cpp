#include <stdio.h>
#include <malloc.h>

void insertSort(int* s, int n)
{
	for (int i(1); i < n; i++)
	{
		int temp = s[i];
		for (int j = i - 1; j >= 0 && s[j] > temp; j--)
		{
			s[j + 1] = s[j];
			s[j] = temp;
		}
	}
}

int binarySearchRecursion(int* s, int x, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (begin > end)
		return -1;
	if (x < s[mid])
		return binarySearchRecursion(s, x, begin, mid - 1);
	if (x > s[mid])
		return binarySearchRecursion(s, x, mid + 1, end);
	return mid;
}


int binarySearchLoop(int* s, int x, int begin, int end)
{
	int mid = (begin + end) / 2;
	while (begin < end)
	{
		mid = (begin + end) / 2;
		if (x < s[mid])
			end = mid - 1;
		if (x > s[mid])
			begin = mid + 1;
		if (x == s[mid])
			break;
	}
	if (x == s[mid])
		return mid;
	else
		return -1;
}
int main()
{
	int n;
	printf_s("please input the length of the numbers:\n");
	scanf_s("%d", &n);
	int* s = (int*)malloc(sizeof(int) * n);
	for (int i(0); i < n; i++)
		scanf_s("%d", s + i);
	insertSort(s, n);
	for (int i(0); i < n; i++)
		printf_s("%d ", *(s + i));
	printf_s("\nplease input the number you want to search:\n");
	int x;
	scanf_s("%d", &x);
	printf_s("binarySearchRecursion:%d\n", binarySearchRecursion(s, x, 0, n - 1) + 1);
	printf_s("binarySearchLoop:%d\n", binarySearchLoop(s, x, 0, n - 1));


	return 0;
}