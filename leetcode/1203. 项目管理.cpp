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
            if(startId[i] == 0)
                if(topSort(graph, startId, q, i) == false)
                {
                    return false;
                }
        }
        return true;
    }

    bool topSort(vector<vector<int>> &graph, vector<int> &isSorted, queue<int> &q, int id)
    {
        if(isSorted[id] == -1)
            return false;
        else
        {
            isSorted[id] = -1;
            for(int x:graph[id])
            {
                q.push(x);
                if(topSort(graph, isSorted, q, x) == false)
                    return false;
            }
        }
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
                        group_graph[x].push_back(group_id + n);
                        group_degree[group_id + n]++;
                    }
                }
                else
                {
                    if(group_id == -1)
                    {
                        group_graph[x_group_id + n].push_back(i);
                        group_degree[i]++;
                    }
                    else
                    {
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
        topSort(group_q, group_graph, group_degree);
        queue<int> inner_q;
        vector<int> ans(n, 0);
        int i = 0;
        while(!group_q.empty())
        {
            int group_id = group_q.front();
            if(group_id < n)
                ans[i] = group_id;
            else
            {
                group_id -= n;
                vector<int> &ids = group_2_id[group_id];
                for()
            }
            
            
            if(ids.size() == 0)
                ans[i] = 
            topSort(inner_graph, inner_degree, inner_q, group_id);

        }
        
        topSort(inner_q, inner_graph, inner_degree);


    }
};