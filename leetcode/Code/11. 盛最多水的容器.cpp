/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
*/

#include <iostream>
#include <vector>

using namespace::std;

int maxArea(vector<int>& height) {
	int begin = 0, end = height.size() - 1;
	int area = 0;
	while (begin < end)
	{
		if (height[begin] > height[end])
		{
			int now_area = (end - begin) * (height[end]);
			if (now_area > area)
				area = now_area;
			int end_height = height[end];
			while (begin<end && end_height >= height[end])
				end--;
		}
		else
		{
			int now_area = (end - begin) * height[begin];
			if (now_area > area)
				area = now_area;
			int begin_height = height[begin];
			while (begin < end && height[begin] <= begin_height)
				begin++;
		}

	}
	return area;
}

int main()
{
	vector<int> height;
	int n;
	cin >> n;
	for (int i(0); i < n; i++)
	{
		int x;
		cin >> x;
		height.push_back(x);
	}
	cout << maxArea(height) << endl;
}

//accepted