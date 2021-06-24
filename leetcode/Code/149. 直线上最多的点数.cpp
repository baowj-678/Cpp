/**
 * @author: Bao Wenjie
 * @date: 2021/6/24
 * @link: https://leetcode-cn.com/problems/max-points-on-a-line/
 */

#include <iostream>
#include <vector>
#include <set>
using namespace::std;

class Solution {
public:
	bool is_line(vector<int>& a, vector<int> & b, vector<int> &c)
	{
        if ((b[0] - a[0]) * (c[1] - a[1]) == (c[0] - a[0]) * (b[1] - a[1]))
            return true;
        return false;
	}
	
    int maxPoints(vector<vector<int>>& points) {
        set<int> S;
        int max_ = 2;
    	for(int i = 0; i < points.size(); i++)
    	{
            S.clear();
    		for(int j = i + 1; j < points.size(); j++)
    		{
    			if(S.find(j) != S.end())
                    continue;
                S.insert(j);
                int cnt = 2;
    			for(int k = i + 1; k < points.size(); k++)
    			{
    				if(k == j)
                        continue;
    				if(is_line(points[i], points[j], points[k]))
    				{
                        cnt++;
                        S.insert(k);
    				}
    			}
                max_ = max(max_, cnt);
    		}
    	}
        return max_;
    }
};