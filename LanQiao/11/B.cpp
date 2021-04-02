/**
 * Author: Bao Wenjie
 * Date: 2021/4/2
 * Description: 蓝桥杯第十一届B题 
 */

#include <cstdio>

bool EuclideanAlgorithm(int a, int b)
{
	int tmp;
	if(a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	while(b!=0)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	if(a > 1)
		return true;
	return false;
}

int main()
{
	int sum = 0;
	for(int i = 1; i < 2020; i++)
	{
		for(int j = i + 1; j <= 2020; j++)
		{
			if(!EuclideanAlgorithm(i, j))
			{
				sum += 2;
			}
		}
	}
	printf("%d\n", sum);
	
}


