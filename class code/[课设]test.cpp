#include <iostream>
#include <stdio.h>
using namespace std;

int is_on[400][400];

int hourse(int board[400][400], int n, int m, int x, int y)
{
	if (board[x][y] == -1)
		return -1;
	if (board[x][y] != 99999)
		return board[x][y];
	if (is_on[x][y] == 1)
		return 99999;

	is_on[x][y] = 1;
	int distance[8];
	int i;

	for (i = 0; i < 8; i++)
		distance[i] = 99999;

	int is
	if (0 <= x - 1 && 0 <= y - 2)
		distance[0] = hourse(board, n, m, x - 1, y - 2);
	if (0 <= x - 1 && y + 2 < m)
		distance[1] = hourse(board, n, m, x - 1, y + 2);
	if (0 <= x - 2 && 0 <= y - 1)
		distance[2] = hourse(board, n, m, x - 2, y - 1);
	if (0 <= x - 2 && y + 1 < m)
		distance[3] = hourse(board, n, m, x - 2, y + 1);
	if (x + 1 < n && 0 <= y - 2)
		distance[4] = hourse(board, n, m, x + 1, y - 2);
	if (x + 1 < n && y + 2 < m)
		distance[5] = hourse(board, n, m, x + 1, y + 2);
	if (x + 2 < n && 0 <= y - 1)
		distance[6] = hourse(board, n, m, x + 2, y - 1);
	if (x + 2 < n && y + 1 < m)
		distance[7] = hourse(board, n, m, x + 2, y + 1);
	
	for (i = 0; i < 8; i++)
	{
		if (distance[i] == -1)
			distance[i] = 99999;
	}
	int min = distance[0];
	for (i = 0; i < 8; i++)
	{
		if (distance[i] < min)
		{
			min = distance[i];
		}
	}
	if (min < 99999)
		board[x][y] = min + 1;
	else
		board[x][y] = -1;
	
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < m; j++)
		{
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	
	is_on[x][y] = 0;
	return board[x][y];
}

int main()
{
	int n = 4;
	int m = 4;
	int x = 2;
	int y = 2;
	int board[400][400];
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			board[i][j] = 99999;
		}
	}
	board[x - 1][y - 1] = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			hourse(board, n, m, i, j);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}
