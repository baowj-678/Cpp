/**
* Topic: CSP-2018-3-Æå¾ÖÆÀ¹À
* Author: Bao Wenjie
* Email: bwj_678@qq.com
* Date: 2020/8/22
*/

#include <iostream>
#include <cstdio>

#define ALICE	1
#define	BOB		2
#define	SIZE	3
using namespace::std;

int Board[SIZE][SIZE];
bool judge(int Board[SIZE][SIZE], int characetr);
int dfs(int Board[SIZE][SIZE], int characetr);
int main()
{
	int n;
	cin >> n;
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < SIZE; j++)
			scanf_s("%d%d%d", Board[j], Board[j] + 1, Board[j] + 2);
		int score = dfs(Board, ALICE);
		printf("%d\n", score);
	}
}

/**
* ÅÐ¶ÏcharacterÊÇ·ñÊ¤Àû
*/
bool judge(int Board[SIZE][SIZE], int characetr)
{
	bool win = false;
	if ((Board[0][0] == characetr && Board[1][1] == characetr && Board[2][2] == characetr) ||
		(Board[0][2] == characetr && Board[1][1] == characetr && Board[2][0] == characetr))
		return true;
	for (int i(0); i < SIZE; i++)
	{
		if (Board[0][i] == characetr && Board[1][i] == characetr && Board[2][i] == characetr)
		{
			win = true;
			break;
		}
		else if(Board[i][0] == characetr && Board[i][1] == characetr && Board[i][2] == characetr)
		{
			win = true;
			break;
		}
	}
	if (win)
		return true;
	return false;
}

/**
* ËÑË÷
*/
int dfs(int Board[SIZE][SIZE], int characetr)
{
	int cnt = 0;
	for (int i(0); i < SIZE; i++)
		for (int j(0); j < SIZE; j++)
			if (Board[i][j] == 0)
				cnt++;
	if (characetr == BOB && judge(Board, ALICE)) return cnt + 1;
	if (characetr == ALICE && judge(Board, BOB)) return -cnt - 1;
	if (cnt == 0) return 0;
	int mn = -1000000, mx = 1000000;
	for(int i(0);i<SIZE;i++)
		for(int j(0);j<SIZE;j++)
			if (Board[i][j] == 0)
			{
				Board[i][j] = characetr;
				if (characetr == ALICE)
					mn = max(mn, dfs(Board, BOB));
				else
					mx = min(mx, dfs(Board, ALICE));
				Board[i][j] = 0;
			}
	if (characetr == ALICE)
		return mn;
	else
		return mx;
}