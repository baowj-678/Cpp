//参考网址 https://www.bilibili.com/video/BV1ZE41177JM?p=12
//Description: Jarvis March算法
//Author: Bao Wenjie
//Date: 2020/8/4
//Email: bwj_678@qq.com
#pragma once
#include "convex hull.h"




/**
* @description: Jarvis March算法 O(n2)
* @param S: 点的集合
* @param n: 点的个数
*/
void Jarvis_March(Point S[], int n)
{
	/*数据预处理*/
	for (int i(0); i < n; i++)
		S[i].setExtreme(false);
	int ltl = LTL(S, n);
	int k = ltl;


	do {
		S[k].setExtreme(true);
		// k:上一个节点
		// s:记录下一个选中节点
		// t:枚举每个节点
		int s = -1;
		for (int t = 0; t < n; t++)
			if(t != k && t != s &&
				(s == -1 || ! ToLeft(S[k], S[s], S[t])))
				/* 更新s点 */
				s = t;
		k = s;
	// 如果到达起点
	} while (ltl != k);
}

/**
* @decription: LeftMost-Then-LowMost初始化
* @param S: 结点集合
* @param n: 结点个数
*/
int LTL(Point S[], int n)
{
	int ltl = 0;
	for (int k = 1; k < n; k++)
		if (S[k].getY() < S[ltl].getY() ||
			(S[k].getY() == S[k].getY() && S[k].getX() < S[ltl].getX()))
			ltl = k;
	return ltl;
}