#include <stdio.h>

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
					break;
			}
			A[j] = Tmp;
		}
	}
}

void solve(int n) {
	if (n < 10)
	{
		printf("%d", n);
		return;
	}
	printf("%d", n % 10);
	solve(n / 10);
	
	return;
}

int main()
{
	solve(8349);
}