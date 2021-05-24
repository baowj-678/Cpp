/**
 * @author: Bao Wenjie
 * @date: 2021/5/24
 * @link: https://www.luogu.com.cn/problem/P1091
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 105
#define scanf scanf_s

int heights[MAXN];
int up_[MAXN];
int down_[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	std::vector<int> down, up;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		heights[i] = x;

		bool is_con = false;
		if (up.size() == 0)
		{
			up.push_back(x);
			is_con = true;
		}
		else
		{
			if (up.back() < x)
			{
				up.push_back(x);
				is_con = true;
			}
			else
			{
				for (int j = 0; j < up.size(); j++)
				{
					if (x <= up[j])
					{
						up[j] = x;
						break;
					}
				}
			}
		}
		if(is_con)
			up_[i] = up.size();
		else
		{
			for(int j = i - 1; j >= 0; j--)
			{
				if(heights[j] < x)
				{
					up_[i] = up_[j] + 1;
					break;
				}
			}
		}
	}
	for(int i = n - 1; i >= 0; i--)
	{
		int x = heights[i];
		bool is_con = false;
		if (down.size() == 0)
		{
			down.push_back(x);
			is_con = true;
		}
		else
		{
			if (down.back() < x)
			{
				down.push_back(x);
				is_con = true;
			}
			else
			{
				for (int j = 0; j < down.size(); j++)
				{
					if (x <= down[j])
					{
						down[j] = x;
						break;
					}
				}
			}
		}
		if(is_con)
			down_[i] = down.size();
		else
		{
			for(int j = i + 1; j < n; j++)
			{
				if(heights[j] < x)
				{
					down_[i] = down_[j] + 1;
					break;
				}
			}
		}
	}
	int min_ = 999999;
	for(int i = 0; i < n; i++)
	{
		min_ = std::min(n - (up_[i] + down_[i] - 1), min_);
	}
	printf("%d\n", min_);
	return 0;
}
