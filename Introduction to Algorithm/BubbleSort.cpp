#include <iostream>

using namespace::std;
void bubbleSort(int* s, int n)
{
	for (int i(n - 1); i > 0; i--)
	{
		for (int j(0); j < i; j++)
		{
			if (s[j] > s[j + 1])
			{
				int key = s[j];
				s[j] = s[j + 1];
				s[j + 1] = key;
			}
		}
	}
}

int bubble_sort_main()
{
	int n;
	cin >> n;
	int* s = new int[n];
	for (int i(0); i < n; i++)
	{
		cin >> s[i];
	}
	bubbleSort(s, n);
	for (int i(0); i < n; i++)
	{
		cout << s[i] << " ";
	}
	return 0;
}