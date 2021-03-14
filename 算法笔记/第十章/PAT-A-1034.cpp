/**
 * Author: Bao Wenjie
 * Date: 2021/3/14
 * Link: https://pintia.cn/problem-sets/994805342720868352/problems/994805456881434624
 */


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#define scanf scanf_s

using namespace ::std;

int Find(vector<int>& human, int index)
{
	int i = index;
	while (human[index] != index)
	{
		index = human[index];
	}
	while (i != index)
	{
		int tmp = human[i];
		human[i] = index;
		i = tmp;
	}
	return index;
}

void Union(vector<int>& human, vector<int>& weight, vector<int>& w, vector<int>& max_id, vector<int>& n, int a, int b)
{
	int x = Find(human, a);
	int y = Find(human, b);
	if (x == y)
		return;
	n[y] += n[x];
	human[x] = y;
	weight[y] += weight[x];
	max_id[y] = max_id[y] ? w[y] > w[x]:max_id[x];
}

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
	return a.first < b.first;
}

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	map<string, int> name2id;
	map<int, string> id2name;
	vector<int> human;
	vector<int> weight;
	vector<pair<int, int>> vec_pair;
	for(int i = 0; i < N; i++)
	{
		string s;
		int a, b, w;
		cin >> s;
		if (name2id.find(s) == name2id.end())
		{
			a = name2id.size();
			name2id.insert(pair<string, int>(s, a));
			id2name.insert(pair<int, string>(a, s));
			human.push_back(a);
			weight.push_back(0);
		}
		else
			a = name2id[s];
		s.clear();
		cin >> s;
		if (name2id.find(s) == name2id.end())
		{
			b = name2id.size();
			name2id.insert(pair<string, int>(s, b));
			id2name.insert(pair<int, string>(b, s));
			human.push_back(b);
			weight.push_back(0);
		}
		else
			b = name2id[s];
		scanf("%d", &w);
		weight[a] += w;
		weight[b] += w;
		vec_pair.push_back({ a, b });
	}
	vector<int> w = weight;
	vector<int> max_id = human;
	vector<int> n(human.size(), 1);
	for(pair<int, int>& p:vec_pair)
	{
		Union(human, weight, w, max_id, n, p.first, p.second);
	}
	vector<pair<string, int>> ans;
	for(int i = 0; i < human.size(); i++)
	{
		if(i == human[i] && weight[i]/2 > K && n[i] > 2)
		{
			int id = max_id[i];
			int num = n[i];
			ans.push_back({ id2name[max_id[i]], num });
		}
	}
	printf("%d", ans.size());
	sort(ans.begin(), ans.end(), cmp);
	if (ans.size() != 0)
		printf("\n");
	int i = 0;
	for(pair<string, int>& p : ans)
	{
		printf("%s %d", p.first.c_str(), p.second);
		if (++i < ans.size())
			printf("\n");
	}
	return 0;
}