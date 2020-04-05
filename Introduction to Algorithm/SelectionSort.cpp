#include <iostream>

using namespace::std;

void selectionSort(int* s, int n)//from small to big
{
	for (int i(0); i < n; i++)
	{
		int key = s[i];
		for (int j = i + 1; j < n; j++)
		{
			if (s[j] < key)
			{
				s[i] = s[j];
				s[j] = key;
				key = s[i];
			}
		}
	}
}

int select_sort_main()
{
	int n;
	cin >> n;
	int* s = new int[n];
	for (int i(0); i < n; i++)
	{
		cin >> s[i];
	}
	selectionSort(s, n);
	for (int i(0); i < n; i++)
	{
		cout << s[i] << " ";
	}
	return 0;
}