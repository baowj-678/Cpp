#include "basic_array_function.h"
#include <iostream>

using namespace::std;

long long matrix_chain_order(int nums[], int n);
void print_optimal_parens(int** s, int i, int j);
int main()
{
	int n;
	cout << "Please input the number of matrix:\n";
	cin >> n;
	cout << "Please input the dim of matrix in order:\n";
	int* nums = new int[n + 1];
	for (int i(0); i <= n; i++)
	{
		cin >> nums[i];
	}
	for (int i(0); i <= n; i++)
	{
		cout << nums[i]  <<" ";
	}
	cout << endl;
	cout << "\nThe least times of mal is:\n" << matrix_chain_order(nums, n) << endl;
}

// length(nums) = n + 1
long long matrix_chain_order(int nums[], int n)
{
	// get memory
	long long** m = zerosTwoDimMatrix<long long>(n, n);
	int** s = zerosTwoDimMatrix<int>(n, n);

	// init variables
	int i, j, k, l;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			m[i][j] = 0;

	//l:chain length
	for (l = 2; l <= n; l++)
	{
		for (i = 0; i <= n - l; i++)
		{
			// the position to be update
			j = i + l - 1;
			m[i][j] = (long long)9223372036854775807;
			for (k = i; k < j; k++)
			{
				long long q = m[i][k] + m[k + 1][j] + nums[i] * nums[k + 1] * nums[j + 1];
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	printTwoDimMatrix<long long>(m, n, n);
	cout << "The order is:\n";
	print_optimal_parens(s, 0, n - 1);
	long long ans = m[0][n - 1];
	// delete memory
	delTwoDimMatrix<long long>(m, n);
	delTwoDimMatrix<int>(s, n);
	return ans;
}

void print_optimal_parens(int** s, int i, int j)
{
	if (i == j)
		cout << "A(" << i + 1 << ")";
	else
	{
		cout << "(";
		print_optimal_parens(s, i, s[i][j]);
		print_optimal_parens(s, s[i][j] + 1, j);
		cout << ")";
	}
	return;
}

//30 35 15 5 10 20 25