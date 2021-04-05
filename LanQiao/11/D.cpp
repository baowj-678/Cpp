/**
 * Author: Bao Wenjie
 * Date: 2021/4/5
 * Description: 蓝桥杯第十一届D题 
 */

#include <cstdio>
int g[7][7], is_visited[7];
int cnt = 0;
void dfs(int index, bool begin)
{
	if(is_visited[index] == 1)
	{
		cnt ++;
		return; 
	}
	is_visited[index] = 1;
	if(begin)
	{
		cnt++;
		for(int i = 0; i < 7; i++)
		{
			if(g[index][i] == 1)
			{
				dfs(i, begin);
			}
		}
	}
	else
	{
		for(int i = 0; i < 7; i++)
		{
			if(g[index][i] == 1)
			{
				dfs(i, false);
				dfs(i, true);
			}
		}
	}
	is_visited[index] = 0;
}

int main()
{
	for(int i = 0; i < 7; i++)
	{
		is_visited[i] = 0;
		for(int j = 0; j < 7; j++)
		{
			g[i][j] = 0;
		}
	}
	
} 
