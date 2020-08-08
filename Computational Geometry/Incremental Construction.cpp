//参考网址 https://www.bilibili.com/video/BV1ZE41177JM?p=18
//Description: 凸包问题的Incremental算法
//Author: Bao Wenjie
//Date: 2020/8/4
//Email: bwj_678@qq.com
#include "convex hull.h"

/**
* @description: Increment算法
* @param S: 点集
* @param n: 个数
*/
void Incremental_Construction(Point S[], int n)
{
	/* 初始化为false(非凸包的点) */
	for (int i = 0; i < n; i++)
		S[i].setExtreme(false);
	/* 主循环 */
	LinkedList* ll = new LinkedList();
	ll->addHeadNext(S);
	ll->addHeadNext(S + 1);
	for (int i = 2; i < n; i++)
		Add_Point(ll, S + i);
	/* 标记 */
	LinkedListPoint* head = ll->getHead();
	LinkedListPoint* tmp = head->getNext();
	head->getPoint()->setExtreme(true);
	while (tmp != head)
	{
		tmp->getPoint()->setExtreme(true);
		tmp = tmp->getNext();
	}
}

/**
* @description: 判断point点能否添加到链表ll中
* @param ll: 循环链表
* @param point: 点
*/
void Add_Point(LinkedList* ll, Point* point)
{
	LinkedListPoint* tmp = ll->getHead();
	/* 结点数小于2：直接添加 */
	if (ll->getSize() < 2)
		ll->addToNext(tmp, point);
	else 
	{
		LinkedListPoint* a = nullptr;
		LinkedListPoint* b = nullptr;
		bool a_ = ToLeft(*point, *tmp->getPoint(), *tmp->getNext()->getPoint());
		while (!(a && b))
		{
			bool t = ToLeft(*point, *tmp->getPoint(), *tmp->getNext()->getPoint());
			if (a_ == true && t == false)
				a = tmp;
			else if(a_ == false && t == true)
				b = tmp;
			a_ = t;
		}
		ll->linkAB(a, b);
		ll->addToNext(a, point);
	}
}