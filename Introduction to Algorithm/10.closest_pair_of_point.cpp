#include <iostream>
#include <vector>
#include <algorithm>
#include "basic_array_function.h"
using namespace::std;

struct point {
	double x;
	double y;
	point(double x, double y) :x(x), y(y) {}
};

bool cmp_x(const point* A, const point* B)  // 比较x坐标
{
	return A->x < B->x;
}

bool cmp_y(const point* A, const point* B)  // 比较y坐标
{
	return A->y < B->y;
}

double distancePoint(const point* A, const point* B)
{
	return sqrt(pow(A->x - B->x, 2) + pow(A->y - B->y, 2));
}

double merge(point* points[], int begin, int end, double dis, int mid)//[begin, end)
{
	vector<point*> left, right;
	for (int i = begin; i < end; ++i)  // 搜集左右两边符合条件的点
	{
		if (points[i]->x - points[mid]->x <= 0 && points[i]->x - points[mid]->x > -dis)
			left.push_back(points[i]);
		else if (points[i]->x - points[mid]->x > 0 && points[i]->x - points[mid]->x < dis)
			right.push_back(points[i]);
	}
	sort(right.begin(), right.end(), cmp_y);
	for (int i = 0, index; i < left.size(); ++i)  // 遍历左边的点集合，与右边符合条件的计算距离
	{
		for (index = 0; index < right.size() && left[i]->y < right[index]->y - dis; ++index);
		for (int j = 0; j < 7 && index + j < right.size(); ++j)
		{
			if (distancePoint(left[i], right[j + index]) < dis)
				dis = distancePoint(left[i], right[j + index]);
		}
	}
	return dis;
}

double closest(point* points[], int begin, int end)//[begin, end)
{
	if (end - begin == 2)
		return distancePoint(points[begin], points[begin + 1]);
	if (end - begin == 3)
		return min(distancePoint(points[begin], points[begin + 1]), min(distancePoint(points[begin], points[begin + 2]), distancePoint(points[begin + 1], points[begin + 2])));
	int mid = (begin + end - 1) / 2;
	double d_left = closest(points, begin, mid + 1);
	double d_right = closest(points, mid + 1, end);
	double d = min(d_left, d_right);
	return merge(points, begin, end, d, mid);


}

void printPoints(point* points[], int n)
{
	for (int i(0); i < n; i++)
	{
		cout << setiosflags(ios::left)<< "(" << points[i]->x << "," << points[i]->y << ")  ";
		if (i % 8 == 0 && i != 0)
			cout << endl;
	}
	cout << endl;
}

double closestPoint(point* points[], int begin, int end)
{
	double dis = INFINITY;
	double temp = 0;
	for (int i(begin); i < end; i++)
	{
		for (int j(i + 1); j < end; j++)
		{
			temp = distancePoint(points[i], points[j]);
			if (temp < dis)
				dis = temp;
		}
	}
	return dis;
}

int main()
{
	int n;
	n = 200;
	point** points = new point*[n];
	double* x = array_generate_double<double>(n, 0, 10);
	double* y = array_generate_double<double>(n, 0, 10);
	for (int i(0); i < n; i++)
	{
		points[i] = new point(x[i], y[i]);
	}
	sort(points, points + n - 1, cmp_x);
	printPoints(points, n);
	cout << endl;
	cout << "分治算法" << endl;
	cout << closest(points, 0, n) << endl << endl;
	cout << "普通算法" << endl;
	cout << closestPoint(points, 0, n) << endl;
}