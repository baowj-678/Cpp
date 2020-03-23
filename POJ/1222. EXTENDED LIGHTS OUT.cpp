#include <iostream>

#define X 6
#define Y 5

using namespace::std;
void turn_off(int light[X][Y])
{
	int temp[X][Y];
	int back[X][Y];
	

	for (int a1(0); a1 < 2; a1++)
	{
		for (int a2(0); a2 < 2; a2++)
		{
			for (int a3(0); a3 < 2; a3++)
			{
				for (int a4(0); a4 < 2; a4++)
				{
					for (int a5(0); a5 < 2; a5++)
					{
						for (int i(0); i < X; i++)
						{
							for (int j(0); j < Y; j++)
							{
								temp[i][j] = light[i][j];
								back[i][j] = 0;
							}
						}
						if (a1)
						{

						}

					}
				}
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i(0); i < n; i++)
	{
		int light[X][Y];
		for (int y(0); y < Y; y++)
		{
			for (int x(0); x < X; x++)
			{
				cin >> light[y][x];
			}
		}


		for (int y(0); y < Y; y++)
		{
			for (int x(0); x < X; x++)
			{
				cout << light[y][x] << " ";
			}
			cout << endl;
		}

	}
}
