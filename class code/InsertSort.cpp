#include <stdio.h>

void InsertionSort(int A[], int N)
{
	int j, p;
	int Tmp;
	for (p = 1; p < N; p++)
	{
		Tmp = A[p];
		for (j = p; j > 0 && A[j - 1] > Tmp; j--)
		{
			A[j] = A[j - 1];
		}
		A[j] = Tmp;
	}
}

void ShellSort(int A[], int N)
{
	int i, j, Increment;
	int Tmp;
	for (Increment = N / 2; Increment > 0; Increment /= 2)
	{
		for (i = Increment; i < N; i++)
		{
			Tmp = A[i];
			for (j = i; j >= Increment; j -= Increment)
			{
				if (Tmp < A[j - Increment])
				{
					A[j] = A[j - Increment];
				}
				else
				{
					break;
				}
				A[j] = Tmp;
			}
		}
	}
}

int main()
{

}