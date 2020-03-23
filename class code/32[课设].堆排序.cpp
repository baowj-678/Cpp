#include <stdio.h>


typedef int ElementType;

void PercDown(ElementType A[], int i, int N)
{
	int Child;
	ElementType Tmp;

	for (Tmp = A[i]; 2 * i + 1 < N; i = Child)
	{
		Child = 2 * i + 1;
		if (Child != N - 1 && A[Child + 1] > A[Child])
		{
			Child++;
		}
		if (Tmp < A[Child])
		{
			A[i] = A[Child];
		}
		else
			break;
	}
	A[i] = Tmp;
}

void Swap(ElementType * x, ElementType*y)
{
	ElementType Tmp = *x;
	*x = *y;
	*y = Tmp;
}
void HeapSort(ElementType A[], int N)
{
	int i;

	for (i = N / 2; i >= 0; i--)
	{
		PercDown(A, i, N);
	}
	for (i = N - 1; i > 0; i--)
	{
		Swap(A, A + i);
		PercDown(A, 0, i);
	}
}

int main()
{
	ElementType s[100];
	printf("Please input heapsort n\n");
	int n;
	scanf_s("%d", &n);
	printf("Please input nums\n");
	for (int i = 0; i < n; i++)
		scanf_s("%d", &s[i]);
	HeapSort(s, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", s[i]);
	}
}