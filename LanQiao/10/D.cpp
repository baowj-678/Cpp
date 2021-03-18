/**
 * Author: Bao Wenjie
 * Date: 2021/3/18
 * Description: ¿∂«≈±≠µ⁄ ÆΩÏDÃ‚ 
 */ 

#include <cstdio>
#include <queue>
using namespace::std;

struct node
{
	int x;
	int y;
};
int G[30][50];
bool isVisited[30][50];
char parent[30][50];
int main()
{
	int n = 30, m = 50;
	scanf("%d%d", &n, &m);
	char s[100];
	char ans[1000];
	for(int i = 0; i < n; i++)
	{
		scanf("%s", s);
		for(int j = 0; j < m; j++)
		{
			if(s[j] == '1')
				G[i][j] = 1;
			else
				G[i][j] = 0;
			isVisited[i][j] = false;
		}
	}
	queue<node> Q;
	node tmp;
	tmp.x = 0;
	tmp.y = 0;
	Q.push(tmp);
	isVisited[0][0] = true;
	while(!Q.empty())
	{
		tmp = Q.front();
		Q.pop();
		if(tmp.x == n-1 && tmp.y == m-1)
			break;
		isVisited[tmp.x][tmp.y] = true;
		if(G[tmp.x][tmp.y] == 1 || isVisited[tmp.x][tmp.y])
		{
			continue;
		}
		else
		{
			node temp;
			temp.x = tmp.x + 1;
			temp.y = tmp.y;
			if(temp.x < n && G[temp.x][temp.y] ==0 && isVisited[temp.x][temp.y] == false) // down
			{
				Q.push(temp);
				parent[temp.x][temp.y] = 'D';
			}
			temp.x = tmp.x;
			temp.y = tmp.y - 1;
			if(temp.y >= 0 && G[temp.x][temp.y] == 0 && isVisited[temp.x][temp.y] == false)
			{
				Q.push(temp);
				parent[temp.x][temp.y] = 'L';
			}
			temp.x = tmp.x;
			temp.y = tmp.y + 1;
			if(temp.y < m && G[temp.x][temp.y] == 0 && isVisited[temp.x][temp.y] == false)
			{
				Q.push(temp);
				parent[temp.x][temp.y] = 'R';
			}
			temp.x = tmp.x - 1;
			temp.y = tmp.y;
			if(temp.x >= 0 && G[temp.x][temp.y] == 0 && isVisited[temp.x][temp.y] == false)
			{
				Q.push(temp);
				parent[temp.x][temp.y] = 'U';
			}
		}
	}
	tmp.x = n-1;
	tmp.y = m-1;
	int k = 0;
	while(true)
	{
		if(tmp.x == 0 && tmp.y == 0)
			break;
		char c = parent[tmp.x][tmp.y];
		ans[k++] = c;
		if(c == 'D')
		{
			tmp.x --;
		}
		else if(c == 'L')
		{
			tmp.y ++; 
		}
		else if(c == 'R')
		{
			tmp.y --;
		}
		else 
		{
			tmp.x ++;
		}
	}
	for(int i = k-1; i >= 0; i++)
	{
		printf("%c", ans[i]);
	}
	printf("\n");
	return 0;
} 
