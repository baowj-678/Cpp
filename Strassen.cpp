#include <iostream>
#include <malloc.h>
using namespace::std;

double** matrix_mul(double** A, double** B, int n);
void print(double** M, int n);

int main()
{
	double A[8][8];
	double B[8][8];
	for (int i(0); i < 8; i++)
	{
		for (int j(0); j < 8; j++)
		{
			A[i][j] = B[i][j] = 1;
		}
	}
	print(A, 8);
}

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

void print(double** M, int n)
{
	M = (double(*)[n])M;
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}