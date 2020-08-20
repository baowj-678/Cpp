/**
* Topic: CSP-2018-9-买菜
* Author: Bao Wenjie
* Email: bwj_678@qq.com
* Date: 2020/8/20
*/


//试题名称：	买菜
//时间限制：	1.0s
//内存限制：	256.0MB
//问题描述：
//问题描述
//
//小H和小W来到了一条街上，两人分开买菜，他们买菜的过程可以描述为，去店里买一些菜然后去旁边的一个广场把菜装上车，两人都要买n种菜，所以也都要装n次车。具体的，对于小H来说有n个不相交的时间段[a1, b1], [a2, b2]...[an, bn]在装车，对于小W来说有n个不相交的时间段[c1, d1], [c2, d2]...[cn, dn]在装车。其中，一个时间段[s, t]表示的是从时刻s到时刻t这段时间，时长为t - s。
//由于他们是好朋友，他们都在广场上装车的时候会聊天，他们想知道他们可以聊多长时间。
//
//输入格式
//
//输入的第一行包含一个正整数n，表示时间段的数量。
//接下来n行每行两个数ai，bi，描述小H的各个装车的时间段。
//接下来n行每行两个数ci，di，描述小W的各个装车的时间段。
//
//输出格式
//
//输出一行，一个正整数，表示两人可以聊多长时间。
//
//样例输入
//
//4
//1 3
//5 6
//9 13
//14 15
//2 4
//5 7
//10 11
//13 14
//
//样例输出
//
//3
//
//数据规模和约定
//
//对于所有的评测用例，1 ≤ n ≤ 2000, ai < bi < ai + 1，ci < di < ci + 1, 
//对于所有的i(1 ≤ i ≤ n)有，1 ≤ ai, bi, ci, di ≤ 1000000。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;
struct Time
{
	int begin;
	int end;
};
typedef Time* pTime;
bool cmp (pTime& a, pTime& b)
{
	if (a->begin < b->begin)
		return true;
	else if (a->begin == b->begin)
		return a->end < b->end;
	else
		return false;
}
int main()
{
	// 输入
	int n;
	scanf_s("%d", &n);
	vector<struct Time*> H(n);
	vector<struct Time*> W(n);
	for (int i(0); i < n; i++)
	{
		struct Time* time = new struct Time;
		scanf_s("%d%d", &(time->begin), &(time->end));
		H[i] = time;
	}
	for (int i(0); i < n; i++)
	{
		struct Time* time = new struct Time;
		scanf_s("%d%d", &(time->begin), &(time->end));
		W[i] = time;
	}
	// 排序
	sort(H.begin(), H.end(), cmp);
	sort(W.begin(), W.end(), cmp);
	// 计算
	long long sum = 0;
	int h, w;
	for (h = 0, w = 0; h < n, w < n; )
	{
		if (H[h]->begin <= W[w]->begin)
		{
			if (H[h]->end >= W[w]->end)
			{
				sum += (W[w]->end - W[w]->begin);
				w++;
			}
			else if (H[h]->end >= W[w]->begin)
			{
				sum += (H[h]->end - W[w]->begin);
				h++;
			}
			else
			{
				h++;
			}
		}
		else if(H[h]->begin > W[w]->begin)
		{
			if (W[w]->end >= H[h]->end)
			{
				sum += (H[h]->end - H[h]->begin);
				h++;
			}
			else if (W[w]->end >= H[h]->begin)
			{
				sum += (W[w]->end - H[h]->begin);
				w++;
			}
			else
			{
				w++;
			}
		}
	}
	printf("%lld\n", sum);


}