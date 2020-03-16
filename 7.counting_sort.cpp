#include <iostream>
#include <malloc.h>

using namespace::std;
int counting_sort(int* s, int n);
int getk(int* s, int n);

int main_counting_sort() 
{
	cout << "Counting sort" << endl << "n:" << endl;
	int n;
	cin >> n;
	int s[100];
	for (; n != 0;)
	{
		for (int i(0); i < n; i++)
		{
			cin >> s[i];
		}
		counting_sort(s, n);
		cout << "ans:" << endl;
		for (int i(0); i < n; i++)
			cout << s[i] << " ";
		cout << endl;
		cout << "n:" << endl;
		cin >> n;
	}
	return 0;
}

int counting_sort(int* s, int n)
{
	//get k
	int k = getk(s, n);
	//get memory space
	int* C = (int*)malloc(sizeof(int) * (k + 1));
	int* B = (int*)malloc(sizeof(int) * n);
	//initialization
	for (int i(0); i <= k; i++)
	{
		C[i] = 0;
	}
	//count
	for (int i(0); i < n; i++)
	{
		C[s[i]]++;
	}
	for (int i(1); i <= k; i++)
	{
		C[i] += C[i - 1];
	}
	//sorting
	for (int i(0); i < n; i++)
	{
		B[C[s[i]] - 1] = s[i];
		C[s[i]] --;
	}
	//moving back
	for (int i(0); i < n; i++)
	{
		s[i] = B[i];
	}
	return 0;
}

int getk(int* s, int n)
{
	int k = 0;
	for (int i(0); i < n; i++)
	{
		if (s[i] > k)
			k = s[i];
	}
	return k;
}