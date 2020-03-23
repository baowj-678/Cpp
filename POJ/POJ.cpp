#include <iostream>

#define X 6
#define Y 5

int main()
{
	int n;
	cin << n;
	for (int i(0); i < n; i++)
	{
		int light[X, Y];
		for (int y(0); y < Y; y++)
		{
			for (int x(0); x < X; x++)
			{
				cin >> light[y, x];
			}
		}

		for (int y(0); y < Y; y++)
		{
			for (int x(0); x < X; x++)
			{
				cout << light[y, x] << " ";
			}
			cout << endl;
		}

	}
}

