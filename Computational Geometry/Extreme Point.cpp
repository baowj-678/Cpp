//参考网址 https://www.bilibili.com/video/BV1ZE41177JM?p=12
//Description: 凸包问题的极点解法
//Author: Bao Wenjie
//Date: 2020/8/4
//Email: bwj_678@qq.com

#include <iostream>
#include "..\Computational Geometry\Point.cpp"

using namespace::std;

/**
* @description: 利用行列式计算三角形面积
* @param a\b\p: 三角形三个点
* @return area: 面积
*/
double Area2(Point& a, Point& b, Point& p)
{
	return a.getX() * b.getY() - a.getY() * b.getX() +
		   b.getX() * p.getY() - b.getY() * p.getX() +
		   p.getX() * a.getY() - p.getY() * a.getX();
}
/**
* @description: 判断点p是否在a->b向量的左边
* @param a\b: a->b向量的首尾
* @param p: 待判断的点
* ps:
*
*      |a.x  a.y  1|
* 2s = |b.x  b.y  1|
*      |p.x  p.y  1|
*/
bool ToLeft(Point& a, Point& b, Point& p)
{
	return Area2(a, b, p) > 0;
}

/**
* @description: 判断p点是否在a、b、c三点构成的三角形区域内
* @param a\b\c: 三角形区域的三个顶点
* @param p: 待判断的点
* @return isIn: 是否在区域
*/
bool InTriangle(Point& a, Point& b, Point& c, Point& p)
{
	bool tmp1 = ToLeft(a, b, p);
	bool tmp2 = ToLeft(b, c, p);
	bool tmp3 = ToLeft(c, a, p);
	if (tmp1 == tmp2 && tmp2 == tmp3)
		return true;
	else
		return false;
}
/**
* 计算凸包
* @param S: 点的数组
* @param n: 点的个数
* @return void
**/
void extremePoint(Point S[], int n)
{
	// 将所有节点初始化为凸包
	for (int s = 0; s < n; s++)
	{
		S[s].setExtreme(true);
	}
	for (int p = 0; p < n; p++)
	{
		for (int q = p + 1; q < n; q++)
		{
			for (int r = q + 1; r < n; r++)
			{
				for (int s = 0; s < n; s++)
				{
					if (s == p || s == q || s == r || !S[s].getExtreme())
						continue;
					if (InTriangle(S[p], S[q], S[r], S[s]))
						S[s].setExtreme(false);
				}
			}
		}
	}
}