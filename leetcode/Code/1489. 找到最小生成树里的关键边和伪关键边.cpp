/**
* Link: https://leetcode-cn.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
* Author: Bao Wenjie
* Date: 2021/1/21
*/

#include <vector>
#include <algorithm>
using namespace::std;

struct Edge 
{
    int a;
    int b;
    int value;
    int p;
};
bool cmp(Edge& a, Edge& b)
{
    return a.value < b.value;
}
class Solution {
public:
    bool Union(vector<int>& UF, vector<int>& sz, int x, int y)
    {
        int x_root = Find(UF, x);
        int y_root = Find(UF, y);
        if (x_root == y_root)
            return false;
        UF[y_root] = x_root;
        sz[x_root] += sz[y_root];
        return true;
    }

    int Find(vector<int>& UF, int x)
    {
        while (UF[x] != x)
        {
            x = UF[x];
        }
        return x;
    }

    int MinimalTree(vector<int>& UF, vector<int>& sz, vector<Edge>& edges, int max_t)
    {
        int total = 0;
        for (int i = 0; i < UF.size(); i++)
        {
            UF[i] = i;
            sz[i] = 1;
        }
        for (Edge& edge : edges)
        {
            if (Union(UF, sz, edge.a, edge.b))
            {
                total += edge.value;
                if (sz[Find(UF, edge.a)] == UF.size() || total > max_t)
                {
                    break;
                }
            }
        }
        if (sz[Find(UF, 0)] < UF.size())
            return 9999999;
        return total;
    }

    int MinimalTree(vector<int>& UF, vector<int>& sz, vector<Edge>& edges, int max_t, int k)
    {
        int total = 0;
        for (int i = 0; i < UF.size(); i++)
        {
            UF[i] = i;
            sz[i] = 1;
        }
        Union(UF, sz, edges[k].a, edges[k].b);
        total += edges[k].value;
        for (Edge& edge : edges)
        {
            if (Union(UF, sz, edge.a, edge.b))
            {
                total += edge.value;
                if (sz[Find(UF, edge.a)] == UF.size() || total > max_t)
                {
                    break;
                }
            }
        }
        if (sz[Find(UF, 0)] < UF.size())
            return 9999999;
        return total;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> UF(n, -1);
        vector<int> sz(n, 1);
        vector<Edge> Edges(edges.size());
        for (int i = 0; i < edges.size(); i++)
        {
            Edges[i].a = edges[i][0];
            Edges[i].b = edges[i][1];
            Edges[i].value = edges[i][2];
            Edges[i].p = i;
        }
        sort(Edges.begin(), Edges.end(), cmp);
        int min_total = MinimalTree(UF, sz, Edges, 9999999);
        vector<int> key_edges;
        vector<int> not_key_edges;
        Edge move_out = { 1, 1,1 };
        for (int i = 0; i < edges.size(); i++)
        {
            Edge tmp = Edges[i];
            Edges[i] = move_out;
            int total = MinimalTree(UF, sz, Edges, min_total);
            if (total > min_total)
                key_edges.push_back(tmp.p);
            else 
            {
                Edges[i] = tmp;
                int total = MinimalTree(UF, sz, Edges, min_total, i);
                if (total == min_total)
                    not_key_edges.push_back(tmp.p);
            }
            Edges[i] = tmp;
        }
        return vector<vector<int>>{key_edges, not_key_edges};
    }
};


int main()
{
    int n = 5;
    vector<vector<int>> edges = { {0, 1, 1},{1, 2, 1},{2, 3, 2},{0, 3, 2},{0, 4, 3},{3, 4, 3},{1, 4, 6} };
    Solution so;
    so.findCriticalAndPseudoCriticalEdges(n, edges);
}