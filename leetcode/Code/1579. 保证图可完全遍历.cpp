/**
 * Author: Bao Wen Jie
 * Link: https://leetcode-cn.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
 * Date: 2021/1/28
 */


#include <iostream>
#include <vector>
using namespace ::std;

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

	int Find(vector<int>&UF, int x)
	{
		int tmp = x;
		while(UF[x] != x)
		{
			x = UF[x];
		}
		while(tmp != x)
		{
			int tmp_ = UF[tmp];
			UF[tmp] = x;
			tmp = tmp_;
		}
		return x;
	}
	
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
		vector<int>UF_A(n + 1, -1);
		vector<int>UF_B(n + 1, -1);
		vector<int>sz_A(n + 1, 1);
		vector<int>sz_B(n + 1, 1);
		for (int i = 0; i < n + 1; i++)
		{
			UF_A[i] = i;
			UF_B[i] = i;
		}
		int cnt = 0;
		for(vector<int>& edge:edges)
		{
			if(edge[0] == 3)
			{
				if(Union(UF_A, sz_A, edge[1], edge[2]) &&
				   Union(UF_B, sz_B, edge[1], edge[2]))
				{
					cnt++;
				}
			}
		}
		for(vector<int>& edge:edges)
		{
			if(edge[0] == 1)
			{
				if(Union(UF_A, sz_A, edge[1], edge[2]))
				{
					cnt++;
				}
			}
			else if(edge[0] == 2)
			{
				if(Union(UF_B, sz_B, edge[1], edge[2]))
				{
					cnt++;
				}
			}
		}
		if(sz_A[Find(UF_A, 1)] == n && sz_B[Find(UF_B, 1)] == n)
		{
			return edges.size() - cnt;
		}
		return -1;
    }
};