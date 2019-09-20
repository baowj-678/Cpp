#include <iostream>

using namespace::std;

void insertSort(int* s, int n)//从大到小
{
	for (int i(1); i < n; i++)
	{
		int key = s[i];
		for (int j = i - 1; j >= 0 && s[j] < key; j--)
		{
			s[j + 1] = s[j];
			s[j] = key;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int* s = new int[n];
	for (int i(0); i < n; i++)
	{
		cin >> s[i];
	}
	insertSort(s, n);
	for (int i(0); i < n; i++)
	{
		cout << s[i] << " ";
	}
}