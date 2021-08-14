/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/count-unhappy-friends/
 * @date: 2021/8/14
 */
#include <iostream>
#include <vector>

using namespace::std;


class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<int>a(n, 0);
    	for(vector<int>& pair : pairs)
    	{
            a[pair[0]] = pair[1];
            a[pair[1]] = pair[0];
    	}
        int cnt = 0;
        for(vector<int>& pair : pairs)
        {
            int x = pair[0], y = pair[1];
            vector<int>& x_ref = preferences[x];
            bool is_find = false;
        	for(int u : x_ref)
        	{
        		if(is_find)
                    break;
        		if(u == y)
                    break;
                int v = a[u];
        		for(int tmp_u : preferences[u])
        		{
                    if (tmp_u == x)
                    {
                        cnt++;
                        is_find = true;
                        break;
                    }
                    else if(tmp_u == v)
                    {
	                    break;
                    }
        		}
        	}
            is_find = false;
            vector<int>& y_ref = preferences[y];
            for (int u : y_ref)
            {
            	if(is_find)
                    break;
                if (u == x)
                    break;
                int v = a[u];
                for (int tmp_u : preferences[u])
                {
                    if (tmp_u == y)
                    {
                        cnt++;
                        is_find = true;
                        break;
                    }
                    else if (tmp_u == v)
                    {
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};