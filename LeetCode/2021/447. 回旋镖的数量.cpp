/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/number-of-boomerangs/
 * @date: 2021/9/13
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        vector<int> nums(points.size(), 0);
        vector<map<int, int>> M(points.size(), map<int, int>());
    	for(int i = 0; i < points.size(); i++)
    	{
            vector<int>& pointI = points[i];
    		for(int j = i + 1; j < points.size(); j++)
    		{
                vector<int>pointJ = points[j];
                int dis = (pointI[0] - pointJ[0]) * (pointI[0] - pointJ[0]) +
                    (pointI[1] - pointJ[1]) * (pointI[1] - pointJ[1]);
                if (M[i].find(dis) == M[i].end())
                    M[i][dis] = 0;
                M[i][dis]++;
                if (M[j].find(dis) == M[j].end())
                    M[j][dis] = 0;
                M[j][dis]++;
    		}
    	}
        int ans = 0;
    	for(map<int, int> &tmp : M)
    	{
            map<int, int>::iterator itor;
    		for(itor = tmp.begin(); itor != tmp.end(); itor++)
    		{
                ans += itor->second * (itor->second - 1);
    		}
    	}
        return ans;
    }
};