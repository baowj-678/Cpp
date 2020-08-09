#pragma once
#define	Left	1
#define	Right	2

/* Interval Intersection Detection */
struct Interval
{
	double left;
	double right;
};
struct EndPoint
{
	double value;
	int endpoint;
	EndPoint(double value, int endpoint) { this->value = value; this->endpoint = endpoint; };
};
bool Interval_Intersection_Detection(Interval S[], int n);
int cmp(const void* a, const void* b);