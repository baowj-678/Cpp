/**
 * @author: Bao Wenjie
 * @date: 2021/5/2
 * @link: https://leetcode-cn.com/problems/brick-wall/
 */
#include <iostream>
#include <vector>
#include <map>
using namespace::std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> pos2num;
        int n = wall.size(), p = 0;
    	for(vector<int>& tmp : wall)
    	{
            p = 0;
    		for(int x : tmp)
    		{
                p += x;
                auto a = pos2num.find(p);
    			if(a != pos2num.end())
    			{
                    ++a->second;
    			}
                else
                {
                    pos2num.insert({ p, 1 });
                }
    		}
    	}
        int max_ = 0;
    	for(auto x : pos2num)
    	{
    		if(x.first != p)
				max_ = max(max_, x.second);
    	}
        return n - max_;
    }
};