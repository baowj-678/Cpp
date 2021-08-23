/**
 * @author: Bao Wenjie
 * @date: 2021/6/26
 * @link: https://leetcode-cn.com/problems/sliding-puzzle/
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace::std;


class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        bool is_visited[1000050];
        memset(is_visited, false, sizeof(bool) * 1000000);
        int start = board[0][0] * 100000 + board[0][1] * 10000 + board[0][2] * 1000 +
            board[1][0] * 100 + board[1][1] * 10 + board[1][2];
        queue<int> Q;
        int cnt = 0;
        if (start == 123450)
            return 0;
        Q.push(start);
        is_visited[start] = true;
        Q.push(-1);
        char s[10];
        s[6] = '\0';
        int next[10];
        while (Q.size() > 1)
        {
            int tmp = Q.front();
            Q.pop();
            if (tmp == -1)
            {
                cnt++;
                Q.push(-1);
            }
            if (tmp == 123450)
                return cnt;
            int tmp_ = tmp;
            int index = 0;
            for (int i = 0; i < 6; i++)
            {
                s[5 - i] = tmp % 10 + '0';
                if (tmp % 10 == 0)
                    index = 5 - i;
                tmp /= 10;
            }
            if(index != 2 && index != 5)
            {
                swap(s[index], s[index + 1]);
                tmp_ = atoi(s);
                swap(s[index], s[index + 1]);
            	if(!is_visited[tmp_])
            	{
                    Q.push(tmp_);
                    is_visited[tmp_] = true;
            	}
            }
            if (index != 0 && index != 3)
            {
                swap(s[index], s[index - 1]);
                tmp_ = atoi(s);
                swap(s[index], s[index - 1]);
                if (!is_visited[tmp_])
                {
                    Q.push(tmp_);
                    is_visited[tmp_] = true;
                }
            }
            if (index < 3)
            {
                swap(s[index], s[index + 3]);
                tmp_ = atoi(s);
                swap(s[index], s[index + 3]);
                if (!is_visited[tmp_])
                {
                    Q.push(tmp_);
                    is_visited[tmp_] = true;
                }
            }
            if (index >2)
            {
                swap(s[index], s[index - 3]);
                tmp_ = atoi(s);
                swap(s[index], s[index - 3]);
                if (!is_visited[tmp_])
                {
                    Q.push(tmp_);
                    is_visited[tmp_] = true;
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> board = { {1, 2, 3},{4, 0, 5} };
    Solution solution;
    cout << solution.slidingPuzzle(board);
}