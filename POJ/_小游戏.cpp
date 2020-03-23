#include <iostream>

#define MAX_ROW	100
#define MAX_COL	100
#define DIRECT	4
using namespace::std;

typedef struct point {
	int x;
	int y;
}point;

point operator + (const point &x, const point &y)//point +
{
	point temp;
	temp.x = x.x + y.x;
	temp.y = x.y + y.y;
	return temp;
}
bool operator == (const point& x, const point& y)//point ==
{
	if (x.x == y.x && x.y == y.y)
		return true;
	else
		return false;
}

int board[MAX_ROW][MAX_COL];
bool mark[MAX_ROW][MAX_COL];
int minStep = 10000;

void shortestDistance(int board[][MAX_COL], int row, int col, point x, point y, point lastDirect, int nowStep)
{
	if (nowStep > minStep)
	{
		return;
	}
	if (abs(x.x - y.x) == 1 && abs(x.y - y.y) == 1)
	{
		if (nowStep < minStep)
		{
			minStep = ++nowStep;
			return;
		}
	}
	point direction[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
	for (int i(0); i < DIRECT; i++)
	{
		point temp_x = direction[i] + x;
		if (0 <= temp_x.x && 0 <= temp_x.y && temp_x.x <= row && temp_x.y <= col && board[temp_x.x][temp_x.y] == 0 && mark[temp_x.x][temp_x.y] == false)
		{
			if (lastDirect == direction[i])
			{
				mark[temp_x.x][temp_x.y] = true;//important !!!!!!!!!!!!!!
				shortestDistance(board, row, col, temp_x, y, lastDirect, nowStep);
				mark[temp_x.x][temp_x.y] = false;//important !!!!!!!!!!!!!!
			}
			else
			{
				mark[temp_x.x][temp_x.y] = true;//important !!!!!!!!!!!!!!
				shortestDistance(board, row, col, temp_x, y, direction[i], nowStep + 1);
				mark[temp_x.x][temp_x.y] = false;//important !!!!!!!!!!!!!!
			}
		}
	}

}


int main()
{
	int row, col;
	cout << "please input row col\n";
	cin >> row >> col;
	for (int i(1); i < row + 1; i++)
	{

		for (int j(1); j < col + 1; j++)
		{
			char c;
			cin >> c;
			if (c == 'X')//1 reprent isnot empty
				board[i][j] = 1;
			else
				board[i][j] = 0;//0 reprent is empty
		}
	}
	for (int i(0); i < row + 2; i++)
	{

		for (int j(0); j < col + 2; j++)
		{
			cout << board[i][j]<<" ";
		}
		cout << endl;
	}

	point x, y, lastDirect = { 0,0 };
	cout << "please input x\n";
	cin >> x.x >> x.y;
	cout << "please input y\n";
	cin >> y.x >> y.y;
	memset(mark, false, sizeof(bool) * MAX_ROW * MAX_COL);
	shortestDistance(board, row + 1, col + 1, x, y, lastDirect,0);
	cout << minStep << endl;

}