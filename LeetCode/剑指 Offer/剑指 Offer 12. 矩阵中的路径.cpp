/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
 * @date: 2021/9/20
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
	{
		vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
		for(int i = 0; i < board.size(); i++)
		{
			for(int j = 0; j < board[0].size(); j++)
			{
				if (find(board, isVisited, word, i, j, 0))
					return true;
			}
		}
		return false;
    }

	bool find(vector<vector<char>>& board, vector<vector<bool>>& isVisited,string word, int i, int j, int k)
    {
		if (isVisited[i][j])
			return false;
		if (board[i][j] == word[k])
		{
			isVisited[i][j] = true;
			if (k == word.size() - 1)
				return true;
			if (i > 0 && find(board, isVisited, word, i - 1, j, k + 1))
				return true;
			if (j > 0 && find(board, isVisited, word, i, j - 1, k + 1))
				return true;
			if (i < board.size() - 1 && find(board, isVisited, word, i + 1, j, k + 1))
				return true;
			if (j < board[0].size() - 1 && find(board, isVisited, word, i, j + 1, k + 1))
				return true;
			isVisited[i][j] = false;
		}
		return false;
    }
};

int main()
{
	
}