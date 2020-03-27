#include "basic_array_function.h"
#include <iostream>

using namespace::std;
double** matrix_mul(double** A, double** B, int n);
int main()
{
	int n = 10;
	double** A = zerosTwoDimMatrix(n, n);
	double** B = zerosTwoDimMatrix(n, n);
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			A[i][j] = 1;
			B[i][j] = 1;
		}
	}
	A = matrix_mul(A, B, n);
	printTwoDimMatrix(A, n, n);
}

//double** matrix_mul(double** A, double** B, int n)
//{
//	double* temp = new double[n];
//	int i, j, k;
//	for()
//}

double** matrix_mul(double** A, double** B, int n)
{
	if (n == 0)
		return 0;
	double* row = new double[n];
	double sum = 0;
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			sum = 0;
			for (int k(0); k < n; k++)
			{
				sum += A[i][k] * B[k][j];
			}
			row[j] = sum;
		}
		for (int k(0); k < n; k++)
		{
			A[i][k] = row[k];
		}
	}
	return A;
}