#include "convex hull.h"
#include <iostream>

int main()
{
	int n = 5;
	Point** s = new Point*[n];
	s[0] = new Point(1, 0);
	s[1] = new Point(2, 3);
	s[2] = new Point(4, 7);
	s[3] = new Point(0, 9);
	s[4] = new Point(10, 8);
	Point S[] = { {1, 2}, {2, 3}, {4, 7}, {0, 9}, {10,8}};
	Gram_Scan(s, n);
	for (int i = 0; i < n; i++)
	{
		if (s[i]->getExtreme())
			printf("(%f, %f)\n", s[i]->getX(), s[i]->getY());
	}
}