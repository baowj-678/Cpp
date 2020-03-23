#include <iostream>
#include <cstdlib>
#include <malloc.h>

using namespace::std;

int* randomVector(int n)
{
	int* number = (int*)malloc(n * sizeof(int));
	for (int i(0); i < n; i++)
	{
		number[i] = i + 1;
	}
	for (int i(0); i < n; i++)
	{
		int index = rand() % n;
		int temp = number[i];
		number[i] = number[index];
		number[index] = temp;
	}
	return number;
}
int main()
{
	int n;
	cin >> n;
	int* number = randomVector(n);
	for (int i(0); i < n; i++)
	{
		cout << number[i] << " ";
	}
	cout << endl;
}