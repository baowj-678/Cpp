#include <iostream>
#include "basic_array_function.h"

using namespace::std;

int fastWay(int e[2], int a[][5], int t[][5], int x[2], int n);
void printStation(int** way, int n, int way_star);

/*
int main()
{
	int a[2][5] = {
		{7, 9, 3, 4, 8},
		{8, 5, 6, 4, 5}
	};
	int t[2][5] = {
		{2, 3, 1, 3},
		{2, 1, 2, 2}
	};
	int e[2] = { 2, 4 };
	int x[2] = { 3, 6 };
	int n = 5;
	fastWay(e, a, t, x, n);
}
*/

int fastWay(int e[2], int a[][5], int t[][5], int x[2], int n)
{
	int** f = zerosTwoDimMatrix<int>(2, n);
	int** way = zerosTwoDimMatrix<int>(2, n);
	int i, thisWay, thatWay, f_star, way_star;
	for (i = 0; i < 2; i++)
	{
		f[i][0] = e[i] + a[i][0];
	}
	for (i = 1; i < n; i++)
	{
		//first line
		thisWay = f[0][i - 1] + a[0][i];
		thatWay = f[1][i - 1] + t[1][i - 1] + a[0][i];
		
		if (thisWay <= thatWay)
		{
			f[0][i] = thisWay;
			way[0][i] = 1;
		}
		else
		{
			f[0][i] = thatWay;
			way[0][i] = 2;
		}
		//second line
		thisWay = f[1][i - 1] + a[1][i];
		thatWay = f[0][i - 1] + t[0][i - 1] + a[1][i];
		if (thisWay <= thatWay)
		{
			f[1][i] = thisWay;
			way[1][i] = 2;
		}
		else
		{
			f[1][i] = thatWay;
			way[1][i] = 1;
		}
	}
	if (f[0][n - 1] + x[0] <= f[1][n - 1] + x[1])
	{
		f_star = f[0][n - 1] + x[0];
		way_star = 1;
	}
	else
	{
		f_star = f[1][n - 1] + x[1];
		way_star = 2;
	}
	printStation(way, n, way_star);
	return f_star;
}

void printStation(int** way, int n, int way_star)
{
	int s = way_star - 1;
	cout << "line: " << way_star << ", " << "station: " << n << endl;
	for (int i(n - 1); i > 0; i--)
	{
		s = way[s][i] - 1;
		cout << "line: " << way[s][i] << ", " << "station: " << i << endl;
	}
	cout << endl;
}