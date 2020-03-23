#include "basic_array_function.h"
#include <iostream>

using namespace::std;
double optimal_bst(int n, double p[], double q[]);

int main()
{
	int n = 7;
	double p[] = { 0.04, 0.06, 0.08, 0.02, 0.10, 0.12, 0.14 };
	double q[] = { 0.06, 0.06, 0.06, 0.06, 0.05, 0.05, 0.05, 0.05 };
	cout << optimal_bst(n, p, q);
}

double optimal_bst(int n, double p[], double q[])
{
	// get memory
	int i, j, r, l;
	double now = 0;
	double** e = create_two_dim_array<double>(n + 1, n + 1);
	double** w = create_two_dim_array<double>(n + 1, n + 1);
	int** root = create_two_dim_array<int>(n, n);
	//init
	for (i = 0; i <= n; i++)
	{
		e[i][i] = q[i];					//e[i,i-1]
		w[i][i] = q[i];					//w[i,i-1]
	}
	// l=length for [1, n]
	for (l = 1; l <= n; l++)
	{
		// i + l =[1, n]
		for (i = 0; i < n - l + 1; i++)
		{
			j = i + l;
			e[i][j] = INFINITY;
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			for (r = i; r < j; r++)
			{
				//array_print_two_dim<double>(e, n + 1, n + 1);
				//array_print_two_dim<double>(w, n + 1, n + 1);
				now = e[i][r] + e[r + 1][j] + w[i][j];
				if (now < e[i][j])
				{
					e[i][j] = now;
					root[i][j] = r;
				}

			}
		}
	}
	array_print_two_dim<double>(e, n + 1, n + 1);
	array_print_two_dim<double>(w, n + 1, n + 1);
	now = e[0][n];
	//del_two_dim_array<double>(e, n + 1);
	//del_two_dim_array<double>(w, n + 1);
	//del_two_dim_array<int>(root, n);
	return now;
}