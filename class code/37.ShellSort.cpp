#include <stdio.h>

void ShellSort(int s[], int n)
{
	int i, j, gap, cur;
	for (gap = n; gap > 0; gap = gap / 2)
	{
		for (i = gap; i < n; i++)
		{
			cur = s[i];
			for (j = i; j >= gap && cur < s[j - gap]; j -= gap)
			{
				s[j] = s[j - gap];
			}
			s[j] = cur;
		}
	}
}

int main()
{
	int s[] = { 1,6,8,0,9,2,7.36,8,65,4,2 };
	ShellSort(s, 11);
	for (int i = 0; i < 11; i++)
		printf("%d ", s[i]);
}