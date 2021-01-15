/**
 * Author: Bao Wenjie
 * Date: 2021/1/12
 * Github: https://github.com/baowj-678
 * Source: https://leetcode-cn.com/problems/sort-items-by-groups-respecting-dependencies/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace::std;


class Solution {
public:
    bool topSort(queue<int> &q, vector<vector<int>> &graph, vector<int> &startId)
    {
        for(int i(0); i < startId.size(); i++)
        {
            if (startId[i] == 0)
            {
                if (topSort(graph, startId, q, i) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool topSort(vector<vector<int>> &graph, vector<int> &isSorted, queue<int> &q, int id)
    {
        if(isSorted[id] == -1)
            return false;
        if (isSorted[id] == -2)
            return true;
        q.push(id);
        isSorted[id] = -1;
        for(int x:graph[id])
        {
            if(topSort(graph, isSorted, q, x) == false)
                return false;
        }
        isSorted[id] = -2;
        return true;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> group_graph(m + n, vector<int>());
        vector<vector<int>> inner_graph(n, vector<int>());
        vector<int> group_degree(m + n, 0);
        vector<int> inner_degree(n, 0);
        // construct a map: group -> id
        vector<vector<int>> group_2_id(m, vector<int>());
        for(int i(0); i < group.size(); i++)
        {
            if(group[i] != -1)
            {
                group_2_id[group[i]].push_back(i);
            }
        }
        // construct graph
        for(int i(0); i < beforeItems.size(); i++)
        {
            int group_id = group[i];
            for(int x:beforeItems[i])
            {
                int x_group_id = group[x];
                if(x_group_id == -1)
                {
                    if(group_id == -1)
                    {
                        group_graph[x].push_back(i);
                        group_degree[i]++;
                    }
                    else
                    {
                        group_degree[i] = -1;
                        group_graph[x].push_back(group_id + n);
                        group_degree[group_id + n]++;
                    }
                }
                else
                {
                    group_degree[x] = -1;
                    if(group_id == -1)
                    {
                        group_graph[x_group_id + n].push_back(i);
                        group_degree[i]++;
                    }
                    else
                    {
                        group_degree[i] = -1;
                        if(x_group_id == group_id)
                        {
                            inner_graph[x].push_back(i);
                            inner_degree[i]++;
                        }
                        else
                        {
                            group_graph[x_group_id + n].push_back(group_id + n);
                            group_degree[group_id + n]++;
                        }
                    }
                }
            }
        }
        // Tuopu sort
        queue<int> group_q;
        if (!topSort(group_q, group_graph, group_degree))
            return vector<int>();
        queue<int> inner_q;
        vector<int> ans(n, 0);
        int i = 0;
        while(!group_q.empty())
        {
            int group_id = group_q.front();
            group_q.pop();
            if(group_id < n)
                ans[i++] = group_id;
            else
            {
                group_id -= n;
                vector<int> &ids = group_2_id[group_id];
                bool hasEntrance = false;
                for (int j : ids)
                {
                    if (inner_degree[j] == 0)
                    {
                        hasEntrance = true;
                        if (!topSort(inner_graph, inner_degree, inner_q, j))
                            return vector<int>();

                    }
                }
                if (!hasEntrance)
                    return vector<int>();
                while (!inner_q.empty())
                {
                    ans[i++] = inner_q.front();
                    inner_q.pop();
                }
            }
        }
        return ans;
    }
};

int main()
{
    int m = 3, n = 5;
    vector<int>group = { 1,0,-1,2,0 };
    vector<vector<int>>beforeItem = { {2, 1, 3},{2, 4},{},{},{} };
    Solution so;
    so.sortItems(n, m, group, beforeItem);
}