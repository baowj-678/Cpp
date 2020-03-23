#include <iostream>
#include <algorithm>
#define MAX 101
using namespace::std;
int maxNumber[MAX][MAX];
int temp[MAX];

int maxSumLoop(int maxNumber[MAX][MAX], int n)
{
	for (int i(n); i > 0; i--)
	{
		for (int j(0); j < i; j++)
		{
			temp[j] = maxNumber[i - 1][j] + max(temp[j], temp[j + 1]);
		}
	}
	return temp[0];
}

int main()
{
	int n;
	cin >> n;
	for (int i(0); i < n; i++)
	{
		for (int j(0); j <= i; j++)
		{
			cin >> maxNumber[i][j];
		}
	}
	cout << maxSumLoop(maxNumber, n);
}

//accepted

