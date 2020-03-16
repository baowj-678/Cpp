#include <iostream>

using namespace::std;

void mergeSort(int s[], int begin, int end)
{
	if (begin == end)
		return;
	int mid = (begin + end) / 2;
	mergeSort(s, begin, mid);//sort[begin,mid]
	mergeSort(s, mid + 1, end);//sort[mid+1,end]

	int length = end - begin + 1;//sort [begin,end]
	int* subS = new int[length];
	int temp_begin = begin;
	int temp_mid = mid + 1;
	int i = 0;
	while (temp_begin <= mid && temp_mid <= end)
	{
		if (s[temp_begin] < s[temp_mid])
		{
			subS[i] = s[temp_begin];
			temp_begin++;
			i++;
		}
		else
		{
			subS[i] = s[temp_mid];
			temp_mid++;
			i++;
		}
	}
	while (temp_begin <= mid)
	{
		subS[i] = s[temp_begin];
		temp_begin++;
		i++;
	}
	while (temp_mid <= end)
	{
		subS[i] = s[temp_mid];
		temp_mid++;
		i++;
	}
	for (i = 0; i < length; i++)
	{
		s[begin + i] = subS[i];
	}
	
}


int main()
{
	cout << "Merge sort:" << endl << "n:" << endl;
	int n;
	cin >> n;
	while (n != 0)
	{
		int* s = new int[n];
		for (int i(0); i < n; i++)
		{
			cin >> s[i];
		}
		mergeSort(s, 0, n - 1);
		cout << "ans:" << endl;
		for (int i(0); i < n; i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;
		cout << "n:" << endl;
		cin >> n;
	}
}
