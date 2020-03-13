#include <iostream>
#include "basic_array_function.h"
using namespace::std;

double** matrix_mul(double** A, double** B, double** C, int n);
double** strassen(double** A, double** B, double** C,int n);
double** add(double** A, double** B, double** C, int n);
double** sub(double** A, double** B, double** C, int n);
int main()
{
	int n = 10;
	double** A = create_two_dim_array<double>(n, n);
	double** B = create_two_dim_array<double>(n, n);
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			A[i][j] = 1;
			B[i][j] = 1;
		}
	}
	//A = matrix_mul(A, B, n);
	array_print_two_dim(A, n, n);
}

double** matrix_mul(double** A, double** B, double** C, int n)
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
			C[i][k] = row[k];
		}
	}
	return C;
}


double** strassen(double** A, double** B, double** C, int n)
{
	if (n == 2)
		matrix_mul(A, B, C, 2);
	int newsize = n / 2;
	// get memory
	double** S1 = create_two_dim_array<double>(newsize, newsize);
	double** S2 = create_two_dim_array<double>(newsize, newsize);
	double** S3 = create_two_dim_array<double>(newsize, newsize);
	double** S4 = create_two_dim_array<double>(newsize, newsize);
	double** S5 = create_two_dim_array<double>(newsize, newsize);
	double** S6 = create_two_dim_array<double>(newsize, newsize);
	double** S7 = create_two_dim_array<double>(newsize, newsize);
	double** S8 = create_two_dim_array<double>(newsize, newsize);
	double** S9 = create_two_dim_array<double>(newsize, newsize);
	double** S10 = create_two_dim_array<double>(newsize, newsize);
	double** S11 = create_two_dim_array<double>(newsize, newsize);
	double** S12 = create_two_dim_array<double>(newsize, newsize);
	double** S13 = create_two_dim_array<double>(newsize, newsize);
	double** S14 = create_two_dim_array<double>(newsize, newsize);
	// clac s
	for (int i(0); i < newsize; i++)
	{
		for (int j(0); j < newsize; j++)
		{
			S1[i][j] = B[i][newsize + j] - B[newsize + i][newsize + j];	//[F-H]
			S2[i][j] = A[i][j] + A[i][newsize + j];						//[A+B]
			S3[i][j] = A[newsize + i][j] + A[newsize + i][newsize + j];	//[C+D]
			S4[i][j] = B[newsize + i][j] - B[i][j];						//[G-E]
			S5[i][j] = A[i][j] + A[newsize + i][newsize + j];			//[A+D]
			S6[i][j] = B[i][j] + B[newsize + i][newsize + j];			//[E+H]
			S7[i][j] = A[i][newsize + j] - A[newsize + i][newsize + j];	//[B-D]
			S8[i][j] = B[newsize + i][j] + B[newsize + i][newsize + j];	//[G+H]
			S9[i][j] = A[i][j] - A[newsize + i][j];						//[A-C]
			S10[i][j] = B[i][j] + B[i][newsize + j];					//[E+F]
			S11[i][j] = A[i][j];										//A
			S12[i][j] = B[newsize + i][newsize + j];					//H
			S13[i][j] = B[i][j];										//E
			S14[i][j] = A[newsize + i][newsize + j];					//D
		}
	}
	strassen(S11, S1, S1, newsize);
	strassen(S2, S12, S2, newsize);
	strassen(S3, S13, S3, newsize);
	strassen(S14, S4, S4, newsize);
	strassen(S5, S6, S5, newsize);
	strassen(S7, S8, S6, newsize);
	strassen(S9, S10, S7, newsize);
	// clac I J
	for (int i(0); i < newsize; i++)
	{
		for (int j(0); j < newsize; j++)
		{
			C[i][j] = S5[i][j] + S4[i][j] + S6[i][j] - S2[i][j];
			C[i][newsize + j] = S1[i][j] + S2[i][j];
			C[newsize + i][j] = S3[i][j] + S4[i][j];
			C[newsize + i][newsize + j] = S1[i][j] + S5[i][j] - S7[i][j] - S3[i][j];
		}
	}
	del_two_dim_array<double>(S1, newsize);
	del_two_dim_array<double>(S2, newsize);
	del_two_dim_array<double>(S3, newsize);
	del_two_dim_array<double>(S4, newsize);
	del_two_dim_array<double>(S5, newsize);
	del_two_dim_array<double>(S6, newsize);
	del_two_dim_array<double>(S7, newsize);
	del_two_dim_array<double>(S8, newsize);
	del_two_dim_array<double>(S9, newsize);
	del_two_dim_array<double>(S10, newsize);
	del_two_dim_array<double>(S11, newsize);
	del_two_dim_array<double>(S12, newsize);
	del_two_dim_array<double>(S13, newsize);
	del_two_dim_array<double>(S14, newsize);
	return C;
}

double** add(double** A, double** B, double** C, int n)
{
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	return C;
}

double** sub(double** A, double** B, double** C, int n)
{
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			C[i][j] = A[i][j] - B[i][j];
		}
	}
	return C;
}