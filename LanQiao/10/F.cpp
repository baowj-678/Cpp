/**
 * Author: Bao Wenjie
 * Date: 2021/3/18
 * Description: ¿∂«≈±≠µ⁄ ÆΩÏFÃ‚ 
 */

#include<cstdio>
#include<algorithm>
#include<cmath> 

using namespace::std;
int main()
{
	int n;
	scanf("%d", &n);
	int max_value = 0, max_level = 0;
	int now_value = 0, now_level = 0, now_count = 0;
	int num;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		now_value += num;
		now_count ++;
		if(now_count >= pow(2, now_level))
		{
			now_level++;
			if(now_value > max_value)
			{
				max_value = now_value;
				max_level = now_level;
				now_value = 0;
				now_count = 0;
			}
		}
	}
	printf("%d\n", max_level);
	return 0;
}
