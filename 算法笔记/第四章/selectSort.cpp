/**
* Author: Bao Wenjie
* Description: —°‘Ò≈≈–Ú
* Date: 2021/1/15
*/

void selectSort(int A[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		int k = i;
		for (int j = i + 1; j <= n; j++)
		{
			if (A[j] < A[k])
			{
				k = j;
			}
		}
		int tmp = A[i];
		A[i] = A[k];
		A[k] = tmp;
	}
}