/**
* Topic: CSP-2017-9-¹«¹²Ô¿³×ºĞ
* Author: Bao Wenjie
* Email: bwj_678@qq.com
* Date: 2020/9/3
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define	MAXN	1000 + 5

using namespace::std;

struct Key
{
	int time;
	int num;
};
typedef Key* pKey;
int key_box[MAXN];
int key_to_position[MAXN];
bool cmp(pKey a, pKey b);
int main()
{
	// ³õÊ¼»¯
	int K, N;
	cin >> N >> K;
	for (int i(1); i <= N; i++)
	{
		key_box[i] = key_to_position[i] = i;
	}
	pKey* get = new pKey[K];
	pKey* put = new pKey[K];
	for (int i(0); i < K; i++)
	{
		pKey tmp1 = new Key;
		pKey tmp2 = new Key;
		cin >> tmp1->num;
		tmp2->num = tmp1->num;
		cin >> tmp1->time;
		cin >> tmp2->time;
		tmp2->time += tmp1->time;
		get[i] = tmp1;
		put[i] = tmp2;
	}
	// ÅÅĞò
	sort(get, get + K, cmp);
	sort(put, put + K, cmp);
	// Ä£Äâ
	int i = 0, j = 0;
	vector<int> heap;
	make_heap(heap.begin(), heap.end(), greater<int>());
	while (true)
	{
		// ÄÃÔ¿³×
		if (i < K && get[i]->time < put[i]->time)
		{
			key_box[get[i]->num] = 0;
			heap.push_back(key_to_position[get[i]->num]);
			push_heap(heap.begin(), heap.end(), greater<int>());
			key_to_position[get[i]->num] = 0;
			i++;
		}
		// ·ÅÔ¿³×
		else if(j < K)
		{
			int p = heap.front();
			key_to_position[put[j]->num] = p;
			key_box[p] = put[j]->num;
			pop_heap(heap.begin(), heap.end(), greater<int>());
			heap.pop_back();
			j++;
		}
		else
		{
			break;
		}
	}
	for (int i(1); i <= N; i++)
		cout << key_box[i] << " ";
	cout << endl;
}

bool cmp(pKey a, pKey b)
{
	if (a->time == b->time)
		return a->num < b->num;
	return a-> time < b->time;
}