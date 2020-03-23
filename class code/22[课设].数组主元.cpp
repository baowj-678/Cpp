#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include <memory.h>
#include <stdlib.h>

//线性遍历算法
int CountMainElement(int* nums, int n)
{
	int element = nums[0], amount = 1;
	for (int i = 1; i < n; i++)
	{
		if (amount == 0)
		{
			element = nums[i];
			amount++;
			continue;
		}
		if (nums[i] == element)
			amount++;
		else
			amount--;
	}
	amount = 0;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] == element)
			amount++;
	}
	if (amount > n / 2)
		return element;
	else
		return -1;
}
//递归算法
//如果B C主元相同->A主元就是该主元
//如果B C没有主元->A没有主元
//如果B C主元不同->A主元只可能为其中之一
//如果B C只有一个主元->A主元只可能是它
int RecursionMainElement(int* nums, int begin, int end)
{
	if (begin == end)
		return nums[begin];
	int half = (end - begin) / 2;
	int left = RecursionMainElement(nums, begin, begin + half);
	int right = RecursionMainElement(nums, begin + half + 1, end);
	if (left == right)
		return left;
	if (left == -1 && right == -1)
		return -1;
	if (left == -1)
	{
		int amount = 0;
		for (int i = begin; i <= end; i++)
			if (nums[i] == right)
				amount++;
		if (amount > (end - begin + 1) / 2)
			return right;
		else
			return -1;
	}
	if (right == -1)
	{
		int amount = 0;
		for (int i = begin; i <= end; i++)
			if (nums[i] == left)
				amount++;
		if (amount > (end - begin + 1) / 2)
			return left;
		else
			return -1;
	}
	if (right != left)
	{
		int amountLeft = 0, amountRight = 0;
		for (int i = begin; i <= end; i++)
		{
			if (nums[i] == right)
				amountRight++;
			if (nums[i] == left)
				amountLeft++;
		}
		if (amountLeft > (end - begin + 1) / 2)
			return left;
		else if (amountRight > (end - begin + 1) / 2)
			return right;
		else
			return -1;
	}
}
int CompareCountMainElement(int* s, int n)
{
	int element[500];
	int nums[500];
	memset(nums, 0, sizeof(int));
	int NowP = 0;
	int i = 0;
	for (; i < n; i++)
	{
		int j = 0;
		bool is_exist = false;
		for (; j < NowP; j++)
		{
			if (element[j] == s[i])
			{
				is_exist = true;
				nums[j] ++;
				break;
			}
		}
		if (!is_exist)
		{
			element[NowP] = s[i];
			nums[NowP] = 1;
			NowP++;
		}
	}
	int MainElement = -1;
	for (i = 0; i < NowP; i++)
	{
		if (nums[i] > n / 2)
		{
			MainElement = element[i];
			break;
		}
	}
	return MainElement;
}


int main()
{
	int nums[100];
	printf("Please input n:\n");
	int n;
	scanf_s("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", nums + i);
	}
	printf("MainElement: %d", CountMainElement(nums, n));
}