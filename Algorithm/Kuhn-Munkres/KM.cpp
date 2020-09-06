/**
* @Title: Kuhn-Munkres算法
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/9/6
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
const int INF = 0x3f3f3f3f;

int** get_space(int n, int m);
void free_space(int** graph, int n, int m);
bool find_path_dfs(int u, int* X, int* Y, int* path_X, int* path_Y, int* value_X, int* value_Y, int** graph, int n, int m, int& minz);
int* Kuhn_Munkres(int** graph, int n, int m);
int main()
{
    int n, m;
    cin >> n >> m;
    int** graph = get_space(n, m);
    int k;
    cin >> k;
    int x, y, value;
    for (int i(0); i < k; i++)
    {
        cin >> x >> y >> value;
        *(*(graph + x) + y) = value;
    }
    int* X = Kuhn_Munkres(graph, n, m);
    for (int i(0); i < n; i++)cout << X[i] << " ";
    cout << endl;
    return 0;
}

/**
* 获取存储空间
*/
int** get_space(int n, int m) 
{
    int** ans = new int* [n];
    for (int i(0); i < n; i++)ans[i] = new int[m];
    return ans;
}

/**
* 释放存储空间
*/
void free_space(int** graph, int n, int m)
{
    for (int i(0); i < n; i++)free(graph[i]);
    free(graph);
}

bool find_path_dfs(int u, int* X, int* Y, int* path_X, int* path_Y, int* value_X, int* value_Y, int** graph, int n, int m, int& minz)
{
    path_X[u] = 1;                              //标记进入增广路
    for (int v = 1; v <= m; v++)
    {
        if (!path_Y[v] && graph[u][v] != INF)   //如果Y部的点还没进入增广路,并且存在路径
        {
            int t = value_X[u] + value_Y[v] - graph[u][v];
            if (t == 0)                                 //t为0说明是相等子图
            {
                path_Y[v] = 1;//加入增广路
                // 如果v点未匹配，或者发现增广路
                if (Y[v] == -1 || find_path_dfs(Y[v], X, Y, path_X, path_Y, value_X, value_Y, graph, n, m, minz))
                {
                    X[u] = v;
                    Y[v] = u;
                    return true;
                }
            }
            else if (t > 0)
            {
                minz = min(minz, t);//边权和顶标最小的差值
            }
        }
    }
    return false;
}

int* Kuhn_Munkres(int** graph, int n, int m)
{
    int minz;
    int* X = new int[n];
    int* Y = new int[m];
    int* value_X = new int[n];
    int* value_Y = new int[m];
    int* path_X = new int[n];
    int* path_Y = new int[m];
    memset(X, -1, sizeof(X));
    memset(Y, -1, sizeof(Y));
    memset(value_X, 0, sizeof(value_X));    //wx的顶标为该点连接的边的最大权值
    memset(value_Y, 0, sizeof(value_Y));    //wy的顶标为0
    for (int i = 1; i <= n; i++)            //预处理出顶标值
    {
        for (int j = 1; j <= m; j++)
        {
            if (graph[i][j] == INF) continue;
            value_X[i] = max(value_X[i], graph[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)//枚举X部的点
    {
        while (1)
        {
            minz = INF;
            memset(path_X, 0, sizeof(path_X));
            memset(path_Y, 0, sizeof(path_Y));
            if (find_path_dfs(i, X, Y, path_X, path_Y, value_X, value_Y, graph, n, m, minz)) break;//已经匹配正确
            //还未匹配，将X部的顶标减去minz，Y部的顶标加上minz
            for (int j = 1; j <= n; j++)
                if (path_X[j])value_X[j] -= minz;
            for (int j = 1; j <= m; j++)
                if (path_Y[j])value_Y[j] += minz;
        }
    }
    return X;
}