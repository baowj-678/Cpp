#include <stdio.h>
#include <malloc.h>

int maxWater(int s[], int n)
{
	int left = 0, max_left = 0;
	int right = n - 1, max_right = n - 1;
	int max_water = (n - 1) * (s[left] > s[right] ? s[right] : s[left]);
	while (left < right)
	{
		if (s[left] >= s[right])
		{
			int temp = s[right];
			while (left < right && temp >= s[right])
				right--;
			int water = (right - left) * (s[left] > s[right] ? s[right] : s[left]);
			if (water > max_water)
			{
				max_water = water;
				max_right = right;
				max_left = left;
			}
		}
		else if (s[left] < s[right])
		{
			int temp = s[left];
			while (left < right && temp >= s[left])
				left++;
			int water = (right - left) * (s[left] > s[right] ? s[right] : s[left]);
			if (water > max_water)
			{
				max_water = water;
				max_right = right;
				max_left = left;
			}
		}
	}
	printf_s("max_left:%d,max_right:%d\n", max_left + 1, max_right + 1);
	return max_water;
}

int main()
{
	int n;
	printf_s("please input n\n");
	scanf_s("%d", &n);
	int* s = (int*)malloc(sizeof(int) * n);
	for (int i(0); i < n; i++)
	{
		scanf_s("%d", s + i);
	}
	printf_s("%d\n", maxWater(s, n));
}

//