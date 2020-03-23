#include <stdio.h>
#include <malloc.h>

//最大子数列和 n平方时间
int maxSubSquare(int s[], int n)
{
	int max = 0;
	for (int i(0); i < n; i++)
	{
		int temp_max = 0;
		for (int j = i; j < n; j++)
		{
			temp_max += s[j];
			if (temp_max > max)
				max = temp_max;
		}
	}
	return max;
}


int calcMid(int s[], int left, int mid, int right)
{
	int max = 0, temp_max = 0;
	for (int i(0); i < right - mid + 1; i++)
	{
		temp_max += s[mid + i];
		if (temp_max > max)
			max = temp_max;
	}
	temp_max = max;
	for (int i(1); i < mid - left + 1; i++)
	{
		temp_max += s[mid - i];
		if (temp_max > max)
			max = temp_max;
	}
	return max;
}

//递归方法
int maxSubRecursion(int s[], int left, int right)
{
	if (left == right)
		return s[left];
	int mid = (left + right) / 2;
	int maxLeft = maxSubRecursion(s, left, mid);
	int maxRight = maxSubRecursion(s, mid + 1, right);
	int maxMid = calcMid(s, left, mid, right);
	if (maxLeft > maxRight)
		if (maxLeft > maxMid)
			return maxLeft;
		else
			return maxMid;
	else
		if (maxRight > maxMid)
			return maxRight;
		else
			return maxMid;
}

//线性遍历方法
int maxSubLine(int s[], int n)//O(n)时间
{
	int maxSum = 0, currSum = 0;

	for (int i(0); i < n; i++)
	{
		currSum += s[i];
		if (currSum > maxSum)
			maxSum = currSum;
		if (currSum < 0)
			currSum = 0;
	}
	return maxSum;
}

int main()
{
	int n;
	int s[100];
	printf_s("please input n:\n");
	scanf_s("%d", &n);
	for (int i(0); i < n; i++)
		scanf_s("%d", s + i);
	printf_s("MaxSubLine:%d\n", maxSubLine(s, n));
}