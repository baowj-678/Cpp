//Description: 链表的结构体
//Author: Bao Wenjie
//Date: 2020/8/4
//Email: bwj_678@qq.com

#pragma once
#include "Point.h"
class LinkedListPoint {

private:
	Point* point;
	LinkedListPoint* next;
	LinkedListPoint* last;

public:
	LinkedListPoint(Point* point);
	LinkedListPoint();
	void setNext(LinkedListPoint* next);
	void setLast(LinkedListPoint* last);
	LinkedListPoint* getNext();
	LinkedListPoint* getLast();
	void setPoint(Point* point);
	Point* getPoint();
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void addToNext(LinkedListPoint* nowP, Point* point);
	void addHeadNext(Point* point);
	void linkAB(LinkedListPoint* a, LinkedListPoint* b);
	LinkedListPoint* getHead();
	int getSize();
private:
	LinkedListPoint* head;
	int size;
};

