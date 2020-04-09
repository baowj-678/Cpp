#include <iostream>
#include "basic_array_function.h"
using namespace::std;

int backpack(int w[], int v[], int n, int Weight);

//int main()
//{
//	int w[] = { 3, 4, 5, 6, 7, 8, 9 };
//	int v[] = { 4, 5, 6, 7, 8, 10, 14 };
//	int Weight = 20;
//	cout << backpack(w, v, 7, 20);
//	return 0;
//}

int backpack(int w[], int v[], int n, int Weight)
{
	int** P = zerosTwoDimMatrix<int>(n + 1, Weight + 1);
	int i(0), j(0), value1(0), value2(0), value(0);
	for (i = 0; i <= n; i++)
		P[i][0] = 0;
	for (i = 0; i <= Weight; i++)
		P[0][i] = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= Weight; j++)
		{
			value1 = P[i - 1][j];
			value2 = (Weight - w[i - 1]) > 0 ? P[i - 1][Weight - w[i - 1]] + v[i - 1] : 0;
			P[i][j] = value1 > value2 ? value1 : value2;
		}
	}
	//array_print_two_dim(P, n + 1, Weight + 1);
	value = P[n][Weight];
	delTwoDimMatrix(P, n + 1);
	return value;
}