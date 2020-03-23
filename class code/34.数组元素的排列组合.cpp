#include <stdio.h>

int is_print[100];
int characters[100];
void print(int a[], int n, int num)
{
	if (num >= n - 1)
	{
		int i;
		printf("%d", characters[0]);
		for (i = 1; i < n - 1; i++)
			printf(",%d", characters[i]);
		printf("\n");
		return;
	}

	int i;
	for (i = 0; i < n; i++)
	{
		if (is_print[i] == 0)
		{
			is_print[i] = 1;
			characters[num] = a[i];
			print(a, n, ++num);
			is_print[i] = 0;
			num--;
		}
	}
}

void print_permutation(int a[], int n)
{
	int i;
	int num = 0;
	for (i = 0; i < n; i++)
	{
		is_print[i] = 0;
	}
	print(a, n, num);
}



int main()
{
	int a[] = { 1, 2, 3, 4};
	print_permutation(a, 4);
}