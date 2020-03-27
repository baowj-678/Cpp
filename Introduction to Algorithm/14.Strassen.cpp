#include <iostream>
#include "basic_array_function.h"
#include <time.h>
using namespace::std;

double** matrix_mul(double** A, double** B, double** C, int n);
double** strassen(double** A, double** B, double** C,int n);

int main()
{
	clock_t begin, end;
	int n = 256;
	double** A = zerosTwoDimMatrix<double>(n, n);
	double** B = zerosTwoDimMatrix<double>(n, n);
	double** C = zerosTwoDimMatrix<double>(n, n);
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			A[i][j] = 1;
			B[i][j] = 1;
		}
	}
	double time = 0;
	int m;
	for (int k = 4; k <= 256; k *= 2)
	{
		begin = clock();
		m = 1000;
		for (int i(0); i < m; i++)
			C = matrix_mul(A, B, C, k);
		end = clock();
		cout << ((double)end - begin) / CLOCKS_PER_SEC << ",";
	}
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
	delete[]row;
	return C;
}


double** strassen(double** A, double** B, double** C, int n)
{
	if (n == 1)
	{
		C[0][0] = A[0][0] * B[0][0];
		return C;
	}
	int newsize = n / 2;
	// get memory
	double** S1 = zerosTwoDimMatrix<double>(newsize, newsize);
	double** S2 = zerosTwoDimMatrix<double>(newsize, newsize);
	double** S3 = zerosTwoDimMatrix<double>(newsize, newsize);
	double** S4 = zerosTwoDimMatrix<double>(newsize, newsize);
	double** S5 = zerosTwoDimMatrix<double>(newsize, newsize);
	double** S6 = zerosTwoDimMatrix<double>(newsize, newsize);
	double** S7 = zerosTwoDimMatrix<double>(newsize, newsize);
	double** S8 = zerosTwoDimMatrix<double>(newsize, newsize);
	double** S9 = zerosTwoDimMatrix<double>(newsize, newsize);
	double** S10 = zerosTwoDimMatrix<double>(newsize, newsize);
	double** S11 = zerosTwoDimMatrix<double>(newsize, newsize);
	double** S12 = zerosTwoDimMatrix<double>(newsize, newsize);
	double** S13 = zerosTwoDimMatrix<double>(newsize, newsize);
	double** S14 = zerosTwoDimMatrix<double>(newsize, newsize);
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
	delTwoDimMatrix<double>(S1, newsize);
	delTwoDimMatrix<double>(S2, newsize);
	delTwoDimMatrix<double>(S3, newsize);
	delTwoDimMatrix<double>(S4, newsize);
	delTwoDimMatrix<double>(S5, newsize);
	delTwoDimMatrix<double>(S6, newsize);
	delTwoDimMatrix<double>(S7, newsize);
	delTwoDimMatrix<double>(S8, newsize);
	delTwoDimMatrix<double>(S9, newsize);
	delTwoDimMatrix<double>(S10, newsize);
	delTwoDimMatrix<double>(S11, newsize);
	delTwoDimMatrix<double>(S12, newsize);
	delTwoDimMatrix<double>(S13, newsize);
	delTwoDimMatrix<double>(S14, newsize);
	return C;
}
