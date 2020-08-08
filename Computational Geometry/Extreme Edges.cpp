//参考网址 https://www.bilibili.com/video/BV1ZE41177JM?p=12
//Description: 凸包问题的极边算法
//Author: Bao Wenjie
//Date: 2020/8/4
//Email: bwj_678@qq.com
#include "convex hull.h"


/**
* @description: 检查p/q点是否是极边
* @param S: 所有的点
* @param n: 总点数
* @param p\q: 极边S[p]->S[q]
*/
bool checkEdge(Point S[], int n, int p, int q)
{
	bool LEmpty = true, REmpty = true;
	// 遍历所有点，查看是否在pq同一侧
	for (int k = 0; k < n && (LEmpty || REmpty); k++)
	{
		if (k != p && k != q)
		{
			ToLeft(S[p], S[q], S[k]) ? LEmpty = false : REmpty = false;
		}
	}
	if (LEmpty || REmpty)
	{
		return true;
	}
	else
		return false;
}


/**
* @description: 利用极边算法求出极点
* @param S: 所有点的数组
* @param n: 个数
*/
void Extreme_Edges(Point S[], int n)
{
	// 初始化所有点都不是极点
	for (int k = 0; k < n; k++)
	{
		S[k].setExtreme(false);
	}

	// 枚举所有可能的边
	for (int p = 0; p < n; p++)
	{
		for (int q = p + 1; q < n; q++)
		{
			if (checkEdge(S, n, p, q))
			{
				S[p].setExtreme(true);
				S[q].setExtreme(true);
			}
		}
	}
}