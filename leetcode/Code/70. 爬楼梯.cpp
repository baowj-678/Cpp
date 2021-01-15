#include <iostream>

using namespace::std;

int climbStairsRecursion(int n) {
	if (1 == n || 0 == n)
		return 1;
	return climbStairsRecursion(n - 1) + climbStairsRecursion(n - 2);
}

int climbStairs(int n) {
	int first = 0, second = 0, third = 1;
	for (n; n > 0; n--)
	{
		int temp = third;
		third += second;
		first = second;
		second = temp;
	}
	return third;
}

int main()
{
	int n;
	cin >> n;
	cout << climbStairsRecursion(n) << endl;
	cout << climbStairs(n);
}