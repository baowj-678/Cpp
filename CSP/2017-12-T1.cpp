/**
* Topic: CSP-2017-12-×îÐ¡²îÖµ
* Author: Bao Wenjie
* Email: bwj_678@qq.com
* Date: 2020/8/25
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int main()
{
	vector<int> vec;
	int n, num;
	cin >> n;
	for (int i(0); i < n; i++)
	{
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	int minGap = 9999999;
	for (int i(1); i < n; i++)
	{
		int gap = vec[i] - vec[i - 1];
		if (gap < minGap)
			minGap = gap;
	}
	cout << minGap << endl;
}