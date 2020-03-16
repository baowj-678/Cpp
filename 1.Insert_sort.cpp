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

int main_insert_sort()
{
	cout << "Insert sort" << endl << "n: " << endl;
	int n;
	cin >> n;
	while (n != 0)
	{
		int* s = new int[n];
		for (int i(0); i < n; i++)
		{
			cin >> s[i];
		}
		insertSort(s, n);
		cout << "ans:" << endl;
		for (int i(0); i < n; i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;
		cout << "n:" << endl;
		cin >> n;
	}
	return 0;
}