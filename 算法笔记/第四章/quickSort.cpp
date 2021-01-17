/**
* Description: øÏÀŸ≈≈–Ú
* Author: Bao Wenjie
* Date: 2021/1/17
*/

#include <vector>

using std::vector;

int Partition(vector<int>& A, int left, int right)
{
	int tmp = A[left];
	while (left < right)
	{
		while (left < right && A[right] > tmp)right--;
		A[left] = A[right];
		while (left < right && A[left] <= tmp)left++;
		A[right] = A[left];
	}
	A[left] = tmp;
	return left;
}

void quickSort(vector<int>& A, int left, int right)
{
	if (left < right)
	{
		int pos = Partition(A, left, right);
		quickSort(A, left, pos - 1);
		quickSort(A, pos + 1, right);
	}
}