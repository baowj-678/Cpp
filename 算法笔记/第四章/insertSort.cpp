/**
* Author: Bao Wenjie
* Description: ≤Â»Î≈≈–Ú
* Date: 2021/1/15
*/

void insertSort(int A[], int n)
{
	for (int i = 2; i <= n; i++)
	{
		int tmp = A[i], j = i;
		while (j > 1 && tmp < A[j - 1])
		{
			A[j] = A[j - 1];
			j--;
		}
		A[j] = tmp;
	}
}