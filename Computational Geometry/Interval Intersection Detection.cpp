//参考网址 https://www.bilibili.com/video/BV1ZE41177JM?p=67
//Description: 区间相交检测
//Author: Bao Wenjie
//Date: 2020/8/4
//Email: bwj_678@qq.com

#include <algorithm>
#include"geometric intersection.h"

/**
* @description: 检测区间是否有相交情况
* @param S: 区间集合
* @param n: 区间个数
*/
bool Interval_Intersection_Detection(Interval S[], int n)
{
	/* 将区间拆开 */
	EndPoint** EP = new EndPoint * [2 * n];
	for (int i = 0; i < n; i++)
	{
		EP[i * 2] = new EndPoint(S[i].left, Left);
		EP[i * 2 + 1] = new EndPoint(S[i].right, Right);
	}
	/* 排序 */
	qsort(EP, 2 * n, sizeof(EndPoint*), cmp);
	/* 扫描 */
	bool ans = false;
	int last = EP[0]->endpoint;
	for (int i = 1; i < 2 * n; i++)
	{
		if (EP[i]->endpoint == last)
		{
			ans = true;
			break;
		}
		else
		{
			last = EP[i]->endpoint;
		}
	}
	return ans;
}

/**
* @description: 比较函数
*/
int cmp(const void* a, const void* b)
{
	return (*(EndPoint**)a)->value - (*(EndPoint**)b)->value;
}