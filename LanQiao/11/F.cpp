/**
 * Author: Bao Wenjie
 * Date: 2021/4/5
 * Description: 蓝桥杯第十一届F题 
 */

#include <cstdio>
#include <iostream>
using namespace::std;


int main()
{
	double sum = 0;
	int min_ = 100, tmp;
	int max_ = 0, n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		max_ = max(max_, tmp);
		min_ = min(min_, tmp);
		sum += tmp;
	}
	printf("%d\n%d\n%.2lf\n", max_, min_, sum/n);
}
