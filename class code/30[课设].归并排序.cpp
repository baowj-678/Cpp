#include <stdio.h>

void Merge(int A[], int B[], int Lpos, int Rpos, int RightEnd)
{
	int i, LeftEnd, NumElements, TmpPos;

	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElements = RightEnd - Lpos + 1;

	while (Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if (A[Lpos] <= A[Rpos])
			B[TmpPos++] = A[Lpos++];
		else
			B[TmpPos++] = A[Rpos++];
	}

	while (Lpos <= LeftEnd)
		B[TmpPos++] = A[Lpos++];
	while (Rpos <= RightEnd)
		B[TmpPos++] = A[Rpos++];

	for (i = 0; i < NumElements; i++, RightEnd--)
	{
		A[RightEnd] = B[RightEnd];
	}
}

void MergeSort(int A[], int B[], int begin, int end)
{
	if (begin >= end)
		return;
	int mid = (end + begin) / 2;
	MergeSort(A, B, begin, mid);
	MergeSort(A, B, mid + 1, end);
	Merge(A, B, begin, mid + 1, end);
}

int main()
{
	int A[100];
	int B[100];
	int n;
	printf("Please input merge n\n");
	scanf_s("%d", &n);
	printf("Please input nums\n");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &A[i]);
	}
	MergeSort(A, B, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
}