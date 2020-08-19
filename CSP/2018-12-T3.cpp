/**
* Author: Bao Wenjie
* Email: bwj_678@qq.com
* Date: 2020/8/18
*/
#include <iostream>
#include <algorithm>
#include <list>
using namespace::std;
struct IP {
	short num[4];
	short length;
};
void print(IP ip);
bool check(IP& a, IP& b);
bool operator < (IP& a, IP& b)
{
	for (int i(0); i < 4; i++)
	{
		if (a.num[i] < b.num[i])
			return true;
		else if (a.num[i] > b.num[i])
			return false;
	}
	return a.length < b.length;
}
int main()
{
	int n;
	string in;
	list<IP> linkedList;
	cin >> n;
	for (int i(0); i < n; i++)
	{
		string temp;
		temp.clear();
		IP listNode;
		int pointCount = 0;
		int slashCount = 0;
		cin >> in;
		for (int j(0); j < in.length(); j++)
		{
			if (in[j] == '.')
			{
				listNode.num[pointCount] = atoi(temp.c_str());
				pointCount++;
				temp.clear();
			}
			else if (in[j] == '/')
			{
				slashCount++;
				listNode.num[pointCount] = atoi(temp.c_str());
				pointCount++;
				temp.clear();
			}
			else
			{
				temp.push_back(in[j]);
			}
		}
		if (slashCount == 0)
		{
			listNode.num[pointCount] = atoi(temp.c_str());
			pointCount++;
			listNode.length = 8 * pointCount;
		}
		else
		{
			listNode.length = atoi(temp.c_str());
		}
		if (pointCount < 4)
		{
			for (pointCount; pointCount < 4; pointCount++)
			{
				listNode.num[pointCount] = 0;
			}
		}
		linkedList.push_back(listNode);
	}
	// 排序
	linkedList.sort();
	// 第一次遍历
	list<IP>::iterator itor;
	list<IP>::iterator next;
	itor = linkedList.begin();
	next = itor;
	while (itor != linkedList.end())
	{
		next++;
		if (next == linkedList.end())
			break;
		// itor包含next
		if (check(*itor, *next))
		{
			linkedList.erase(next);
			next = itor;
		}
		// itor不包含next
		else
		{
			itor++;
			next = itor;
		}
	}
	// 输出
	itor = linkedList.begin();
	while (itor != linkedList.end())
	{
		print(*itor);
		itor++;
	}
	// 第二次遍历
	itor = linkedList.begin();
	next = itor;
	if (next != linkedList.end())
	{
		next++;
		while (next != linkedList.end())
		{
			itor->length--;
			if (check(*itor, *next))
			{
				linkedList.erase(next);
				if (itor == linkedList.begin())
				{
					next = itor;
					next++;
				}
				else
				{
					next = itor;
					itor--;
				}
			}
			else
			{
				itor->length++;
				itor = next;
				next++;
			}
		}
	}
	// 输出
	itor = linkedList.begin();
	cout << endl;
	while (itor != linkedList.end())
	{
		print(*itor);
		itor++;
	}
}

/**
* 打印数据
*/
void print(IP ip)
{
	printf_s("%d.%d.%d.%d/%d\n", ip.num[0], ip.num[1], ip.num[2], ip.num[3], ip.length);
}

/**
* 判断a是否包含b
*/
bool check(IP& a, IP& b)
{
	if (a.length <= b.length)
	{
		int n = a.length / 8;
		short numA, numB;
		for (int i(0); i < n; i++)
		{
			if (a.num[i] != b.num[i])
				return false;
		}
		if (n < 4)
		{
			numA = a.num[n];
			numB = b.num[n];
		}
		n = a.length - 8 * n;
		if (n == 0)
			return true;
		for (int i(0); i < n; i++)
		{
			if (numA >> (8 - n) == numB >> (8 - n))
				return true;
		}
	}
	return false;
}