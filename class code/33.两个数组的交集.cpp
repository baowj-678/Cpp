#include <stdio.h>

void PercDown(int s[], int i, int n)
{
	int child = 0;
	int Tmp = s[i];
	for (; 2 * i + 1 < n; i = child)
	{
		child = 2 * i + 1;
		if (child != n - 1 && s[child + 1] > s[child])
		{
			child++;
		}
		if (Tmp < s[child])
		{
			s[i] = s[child];
		}
		else
			break;
	}
	s[i] = Tmp;
}

void Swap(int* x, int* y)
{
	int Tmp = *x;
	*x = *y;
	*y = Tmp;
}

void HeapSort(int s[], int n)
{
	int i;
	for (i = n / 2; i >= 0; i--)
	{
		PercDown(s, i, n-1);
	}
	for (i = n - 1; i >= 0; i--)
	{
		Swap(s, s + i);
		PercDown(s, 0, i);
	}
}


void print_interSection(int a[], int b[], int n)
{
	HeapSort(a, n);
	HeapSort(b, n);
	for (int k = 0; k < n; k++)
		printf("%d ", a[k]);
	printf("\n");
	for (int k = 0; k < n; k++)
		printf("%d ", b[k]);
	printf("\n");
	int i;
	int j;
	for (i = 0, j = 0; i < n && j < n;)
	{
		if (a[i] == b[j])
		{
			printf("%d ", a[i]);
			i++;
			j++;
		}
		else if (a[i] > b[j])
		{
			j++;
		}
		else
		{
			i++;
		}
	}
}


int main()
{
	int a[] = { 12,89,67,56,2,39,0,9,7,8 };
	int b[] = { 56,78,90,0,9,6,5,2,3 ,89 };
	print_interSection(a, b, 10);
}