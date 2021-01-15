/**
* Date: 2020/12/31
* Link: https://leetcode-cn.com/problems/non-overlapping-intervals/
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;


//自定义排序函数  
bool sortFun(vector<int>& p1, vector<int>& p2)
{
    if (p1[0] < p2[0])
    {
        return true;
    }
    else if(p1[0] > p2[0])
    {
        return false;
    }
    else
    {
        if (p1[1] <= p2[1])
            return true;
        return false;
    }
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (internal.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), sortFun);
        int left = intervals[0][0] - 1;
        int right = left;
        int cnt = 0;
        for (vector<int> item : intervals)
        {
            if (item[0] >= right)
            {
                left = item[0];
                right = item[1];
            }
            else
            {
                if (item[1] <= right)
                {
                    left = item[0];
                    right = item[1];
                    cnt++;
                }
                else
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};