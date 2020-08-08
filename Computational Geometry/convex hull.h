//参考网址 https://www.bilibili.com/video/BV1ZE41177JM?p=12
//Description: 凸包问题各种算法
//Author: Bao Wenjie
//Date: 2020/8/4
//Email: bwj_678@qq.com
#pragma once
#include "Point.h"
#include "LinkedList.h"

/* Extreme Point */
double Area2(Point& a, Point& b, Point& p);
bool ToLeft(Point& a, Point& b, Point& p);
bool InTriangle(Point& a, Point& b, Point& c, Point& p);
void Extreme_Point(Point S[], int n);

/* Extreme Edges */
bool checkEdge(Point S[], int n, int p, int q);
void Extreme_Edges(Point S[], int n);

/* Jarvis March */
int LTL(Point S[], int n);
void Jarvis_March(Point S[], int n);

/* Gram Scan */
int LTL(Point* S[], int n);
void Gram_Scan(Point* S[], int n);
void Pre_Sort(Point* S[], int n);
int compare(const void* a, const void* b);

/* Incremental Constuction */
void Incremental_Construction(Point S[], int n);
void Add_Point(LinkedList* ll, Point* point);