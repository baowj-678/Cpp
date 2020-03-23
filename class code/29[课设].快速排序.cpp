#include <stdio.h>

void Swap(int* x, int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

int Median(int A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if (A[Center] > A[Right])
		Swap(&A[Center], &A[Right]);

	
	Swap(&A[Center], &A[Right - 1]);//将“中间值”存储在Right-1
	return A[Right - 1];
}

void Qsort(int A[], int Left, int Right)
{
	int i, j;
	int pivot;
	if (Left + 3 <= Right)
	{
		pivot = Median(A, Left, Right);
		i = Left;
		j = Right-1;
		for (;;)
		{
			while (A[++i] < pivot) {}
			while (A[--j] > pivot) {}
			if (i < j)
				Swap(&A[i], &A[j]);
			else
				break;
		}
		Swap(&A[i], &A[Right - 1]);

		Qsort(A, Left, i - 1);
		Qsort(A, i + 1, Right);
	}
	else
	{
		for (i = Left; i < Right; i++)
		{
			for (j = i + 1; j <= Right; j++)
			{
				if (A[i] > A[j])
					Swap(&A[i], &A[j]);
			}
		}
	}
}


int main()
{
	int A[100];
	int n;
	printf("Please input qsort n\n");
	scanf_s("%d", &n);
	printf("Please input nums\n");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &A[i]);
	}
	Qsort(A, 0, n-1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
}