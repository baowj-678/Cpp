/**
 * @author: Bao Wenjie
 * @date: 2021/6/25
 */
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace::std;


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        bool is_visited[10010];
        int ten[] = { 1, 10, 100, 1000, 10000 };
        for (int i = 0; i < 10000; i++)
            is_visited[i] = false;
        set<int> S;
    	for (string &s : deadends)
    	{
            S.insert(atoi(s.c_str()));
    	}
        queue<int> Q;
        int cnt = 0;
        int tar = atoi(target.c_str());
        is_visited[0] = true;
    	if(S.find(0) == S.end())
			Q.push(0);
        Q.push(-1);
    	while(Q.size() > 1)
    	{
            int x = Q.front();
            Q.pop();
    		if(x == -1)
    		{
                cnt++;
                Q.push(-1);
                continue;
    		}
    		if(x == tar)
    		{
                return cnt;
    		}
    		for(int i = 0; i < 4; i++)
    		{
                int tmp_up = ten[i + 1];
                int tmp = ten[i];
                int x_ = (x % tmp_up) / tmp;
                int num = x - x_ * tmp + ((x_ + 1) % 10) * tmp;
    			if(S.find(num) == S.end() && (!is_visited[num]))
    			{
                    is_visited[num] = true;
                    Q.push(num);
    			}
                num = x - x_ * tmp + ((x_ - 1 + 10) % 10) * tmp;
                if (S.find(num) == S.end() && (!is_visited[num]))
                {
                    is_visited[num] = true;
                    Q.push(num);
                }
    		}
    	}
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<string> strs = { "8887","8889","8878","8898","8788","8988","7888","9888" };
    string target = "8888";
    solution.openLock(strs, target);
}