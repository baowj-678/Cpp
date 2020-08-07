#pragma once
#include "Point.h"

/* Extreme Point */
double Area2(Point& a, Point& b, Point& p);
bool ToLeft(Point& a, Point& b, Point& p);
bool InTriangle(Point& a, Point& b, Point& c, Point& p);
void extremePoint(Point S[], int n);

/* Extreme Edges */
bool checkEdge(Point S[], int n, int p, int q);
void markEE(Point S[], int n);

/* Jarvis March */
int LTL(Point S[], int n);
void Jarvis_March(Point S[], int n);

/* Gram Scan */
int LTL(Point* S[], int n);
void Gram_Scan(Point* S[], int n);
void Pre_Sort(Point* S[], int n);
int compare(const void* a, const void* b);