/**
 * Author: Bao Wenjie
 * Date: 2021/3/18
 * Description: ¿∂«≈±≠µ⁄ ÆΩÏGÃ‚ 
 */

#include <cstdio>
#include <vector>
#include <algorithm> 
using namespace::std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if(a.second == b.second)
	{
		return a.first <= b.first;
	}
	else
		return a.second < b.second;
}

int main()
{
	int N, M, T;
	scanf("%d%d%d", &N, &M, &T);
	vector<pair<int, int> > info(M, {0, 0});
	for(int i = 0; i < M; i++)
	{
		int t, d;
		scanf("%d%d", &t, &d);
		info[i] = {t, d};
	}
	sort(info.begin(), info.end(), cmp);
	int count = 0;
	int value = 0;
	int last_k = 1, k = 1;
	int last_t = 0, t = 0;
	for(int i = 0; i < M; i++)
	{
		pair<int, int>& tmp = info[i];
		if(tmp.second == last_k)
		{
			if(tmp.first == ++last_t)
			{
				value += 2;
			}
			else
			{
				value = value - (tmp.first - last_t) < 0?0:value - (tmp.first - last_t);
			}
			last_t = tmp.first;
		}
		else
		{
			if(last_t == T)
			{
				if(value > 5)
					count++;
			}
			else
			{
				value = value - (T - last_t) < 0?0:value - (T-last_t);
			}
			value = 0;
			last_t = 0;
			last_k = tmp.second;
			i--;
		}
	}
	printf("%d\n", count);
	return 0;
} 
