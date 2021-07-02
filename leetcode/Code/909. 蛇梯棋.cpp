/**
 * @author: Bao Wenjie
 * @date: 2021/6/27
 * @link: https://leetcode-cn.com/problems/snakes-and-ladders/
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace::std;

class Solution {
public:
    int total_width = 0;
    int total_height = 0;
	void get_pos(int num, int &x, int &y)
	{
        y = (num - 1) % this->total_width;
        x = (num - 1) / this->total_width;
		if(x % 2 == 1)
		{
            y = this->total_width - 1 - y;
		}
        x = this->total_height - 1 - x;
	}
	
    int snakesAndLadders(vector<vector<int>>& board) {
        bool is_visited[420];
        for (int i = 0; i < 400; i++)
            is_visited[i] = false;
        this->total_height = board.size();
        this->total_width = board[0].size();
		int target = this->total_height * this->total_width, cnt = 0;
        queue<int> Q;
		is_visited[1] = true;
        Q.push(1);
        Q.push(-1);
		while(Q.size() > 1)
		{
            int x = Q.front();
            Q.pop();
			if(x == target)
			{
                return cnt;
			}
			if(x == -1)
			{
                cnt++;
                Q.push(x);
				continue;
			}
			for(int i = 1; i <= 6; i++)
			{
				int num = x + i;
				if(num <= target && !is_visited[num])
				{
					is_visited[num] = true;
					int x_, y_;
					this->get_pos(num, x_, y_);
					if(board[x_][y_] == -1)
					{
						Q.push(num);
					}
					else
					{
						num = board[x_][y_];
						if(!is_visited[num])
						{
							get_pos(num, x_, y_);
							if(board[x_][y_] == -1)
								is_visited[num] = true;
							Q.push(num);
						}
					}
				}
			}
		}
		return -1;
    }
};

int main()
{
	vector<vector<int>> board = {
		{-1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1},
		{-1, 11, -1, -1, 13, -1},
	};
	Solution solution;
	cout << solution.snakesAndLadders(board);
}