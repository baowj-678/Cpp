#include <stdio.h>
#include <malloc.h>
#include <vector>

using namespace::std;
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

void insertBinarySort(int* s, int n)
{
	for (int i(1); i < n; i++)
	{
		int begin = 0;
		int end = i - 1;
		int mid = (begin + end) / 2;
		while (begin < end)
		{
			mid = (begin + end) / 2;
			if (s[i] < s[mid])
				end = mid - 1;
			else if (s[i] > s[mid])
				begin = mid + 1;
			else
				break;
		}
		if (s[i] != s[mid])
			mid = (end/////////////////////////////////

	}
}


void test1(void)
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
}

void test2(void)
{

}
int main()
{
	

	return 0;
}