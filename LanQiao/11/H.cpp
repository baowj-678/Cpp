/**
 * Author: Bao Wenjie
 * Date: 2021/4/2
 * Description: 蓝桥杯第十一届H题 
 */

#include <cstdio>
#include <cstring>

char s[100005];
int a[26] = {-1}, b[26]={-1};
int main()
{
	memset(a, -1, sizeof(a)/4);
	memset(b, -1, sizeof(b)/4);
	scanf("%s", s);
	int tmp;
	int sum = 0, i;
	for(i = 0; s[i] != 0; i++)
	{
		tmp = s[i] - 'a';
		if(b[tmp] == -1)
		{
			b[tmp] = i;
		}
		else
		{
			sum += (b[tmp] - a[tmp]) * (i - b[tmp]);
			a[tmp] = b[tmp];
			b[tmp] = i;
		}
	}
	for(int j = 0; j < 26; j++)
	{
		if(b[j] == -1)
			continue;
		sum += (b[j] - a[j]) * (i - b[j]);
	}
	printf("%d\n", sum);
	return 0;
}
