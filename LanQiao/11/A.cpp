/**
 * Author: Bao Wenjie
 * Date: 2021/4/2
 * Description: 蓝桥杯第十一届A题 
 */

#include <cstdio>

int main()
{
	int cnt[10] = {0};
	int num;
	for(int i = 1; i <= 2020; i++)
	{
		int tmp = i;
		while(tmp > 0)
		{
			cnt[tmp % 10]++;
			tmp /= 10;	
		}
	}
	for(int i = 0; i < 10; i++)
	{
		printf("%d : %d\n", i, cnt[i]);
	}
}
