/**
 * Author: Bao Wenjie
 * Date: 2021/3/18
 * Description: ¿∂«≈±≠µ⁄ ÆΩÏAÃ‚ 
 */ 

#include <cstdio>

bool isOK(int x)
{
	int nums[] = {2, 0, 1, 9};
	while(x != 0)
	{
		int tmp = x % 10;
		x /= 10;
		for(int i = 0; i < 4; i++)
		{
			if(tmp == nums[i])
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	long long sum = 0;
	for(int i = 1; i <= 2019; i++)
	{
		if(isOK(i))
		{
			sum += i * i;
		}
	}
	printf("%lld\n", sum);
	return 0;
}
