#include <iostream>
#include <time.h>
using namespace::std;

void insertSort(int* s, int n)
{
	for (int i(1); i < n; i++)
	{
		int key = s[i];
		for (int j = i - 1; j >= 0 && s[j] > key; j--)
		{
			s[j + 1] = s[j];
			s[j] = key;
		}
	}
}

int main()
{
	int n;
	clock_t begin, end;
	cin >> n;
	int* s = new int[n];
	for (int i(0); i < n; i++)
	{
		cin >> s[i];
	}
	begin = clock();
	insertSort(s, n);
	end = clock();
	for (int i(0); i < n; i++)
	{
		cout << s[i] << " ";
	}
}