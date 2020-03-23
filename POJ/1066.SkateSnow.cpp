#include <iostream>
#define MAX 101

using namespace::std;

int height[MAX][MAX];
int longestPath(int height[MAX][MAX])
{

}

int main()
{
	int row, col;
	cin >> row >> col;
	for (int i(0); i <= col + 1; i++)
	{
		height[0][i] = 10001;
	}
	for (int i(1); i <= row; i++)
	{
		height[i][0] = 10001;
		for (int j(1); j <= col; j++)
		{
			int x;
			cin >> x;
			height[i][j] = x;
		}
		height[i][col + 1] = 10001;
	}
	for (int i(0); i <= col + 1; i++)
	{
		height[row + 1][i] = 10001;
	}

}
