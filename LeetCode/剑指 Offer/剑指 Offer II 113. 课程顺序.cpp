/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/QA2IGt/
 * @date: 2021/9/5
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> isFind(numCourses, 0);
        vector<int> isVisited(numCourses, 0);
        vector<vector<int>> from(numCourses, vector<int>());
    	for(vector<int>& tmp : prerequisites)
    	{
            from[tmp[0]].push_back(tmp[1]);
    	}
        vector<int> ans;
        for (int i = 0; i < numCourses; i++)
            if (DFS(isFind, isVisited, from, ans, i))
                return vector<int>();
        return ans;
    }

	bool DFS(vector<int>& isFind, vector<int>& isVisited, vector<vector<int>>& from, vector<int>& ans, int cur)
    {
        if (isVisited[cur] == 1)
            return true;
        if (isFind[cur] == 1)
            return false;
        isFind[cur] = 1;
        isVisited[cur] = 1;
        ans.push_back(cur);
    	for(int x : from[cur])
    	{
            if (DFS(isFind, isVisited, from, ans, x))
                return true;
    	}
        isVisited[cur] = 0;
        return false;
    }
};