//ÇóÃİµÄµİ¹é´úÂë
#include <stdio.h>
#include <time.h>

int powRecursionTwo(int x, int n)
{
	if (0 == n)
		return 1;
	if (n % 2 == 1)
		return powRecursionTwo(x * x, n / 2) * x;
	else
		return powRecursionTwo(x * x, n / 2);
}

int LoopPowerThree(int x, int n) {
	int res = 1; 
	if (n == 0) 
		return (1);
	for (; n > 0; n /= 3, x = x * x * x)
	{
		if (n % 3 == 1)
			res *= x;
		if (n % 3 == 2) 
			res *= x * x;
	}
	return res;
}

int LoopPowerTwo(int x, int n) {
	int res = 1;
	if (n == 0) 
		return (1);
	for (; n > 0; n /= 2, x *= x)
	{ 
		if (n % 2 == 1) 
			res *= x; 
	} 
	return res;
}



int powRecursionThree(int x, int n)
{
	if (0 == n)
		return 1;
	if (1 == n)
		return x;
	if (2 == n)
		return x * x;
	if (n % 3 == 1)
		return powRecursionThree(x * x * x, n / 3) * x;
	else if (n % 3 == 2)
		return powRecursionThree(x * x * x, n / 3) * x * x;
	else
		return powRecursionThree(x * x * x, n / 3);
}

int powLoop(int x, int n)
{
	int res = 1;
	while (n > 0)
	{
		if (n % 2)
			res *= x;
		x *= x;
		n /= 2;
	}
	return res;
}

int main()
{
	clock_t beginTwo, endTwo, beginThree, endThree;
	int x, n, i = 0;
	int two, three;
	for (int i = 0; i < 100000; i++)
	{
		for (int j = 0; j < 10000; j++)
		{
			x = i * j;
		}
	}
	//int f = 1000;
	for (int t = 0; t < 1001; t++)
	{
		double timeTwo = 0;
		double timeThree = 0;

		x = 1;
		/*for (int k = -6; k < 6; k++)
		{*/
		n = 300 + t;
		i = 0;
		beginThree = clock();
		for (; i < 100000; i++)
		{
			three = LoopPowerThree(x, n);
		}
		endThree = clock();
		i = 0;

		beginTwo = clock();
		for (; i < 100000; i++)
		{
			two = LoopPowerTwo(x, n);
		}
		endTwo = clock();

		timeTwo = (double)(endTwo - beginTwo) / CLOCKS_PER_SEC;
		timeThree = (double)(endThree - beginThree) / CLOCKS_PER_SEC;
		//}
		printf("%d:", n);
		printf_s("%.3f,", timeTwo);
		printf_s("%.3f;", timeThree);
	}
}