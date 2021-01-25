/**
 * Author: Bao Wenjie
 * Date: 2021/1/25
 * Link: https://leetcode-cn.com/problems/regions-cut-by-slashes/
 */

#include <vector>
#include <iostream>
#include <unordered_set>
using namespace::std;

class Solution {
public:
    void Union(vector<int>& UF, int x, int y)
    {
        int x_root = Find(UF, x);
        int y_root = Find(UF, y);
        UF[y_root] = x_root;
    }

	int Find(vector<int>& UF, int x)
    {
        int tmp = x;
	    while(UF[x] != x)
	    {
            x = UF[x];
	    }
    	while(UF[tmp] != x)
    	{
            int tmp_ = UF[tmp];
            UF[tmp] = x;
            tmp = tmp_;
    	}
        return x;
    }
	
    int regionsBySlashes(vector<string>& grid) {
        int width = grid[0].size();
        int height = grid.size();
        vector<int> UF(width * height * 4, 0);
        for (int i = 0; i < UF.size(); i++)
            UF[i] = i;
    	for(int i = 0; i < height; i++)
    	{
    		for(int j = 0; j < width; j++)
    		{
    			if(grid[i][j] == '/')
    			{
                    Union(UF, i * width * 4 + j * 4 + 0, i * width * 4 + j * 4 + 1);
                    Union(UF, i * width * 4 + j * 4 + 2, i * width * 4 + j * 4 + 3);
                    if (i > 0)
                        Union(UF, (i - 1) * width * 4 + j * 4 + 2, i * width * 4 + j * 4);
                    if (j > 0)
                        Union(UF, i * width * 4 + j * 4 - 1, i * width * 4 + j * 4 + 1);
    			}
                else if(grid[i][j] == '\\')
                {
                    Union(UF, i * width * 4 + j * 4 + 1, i * width * 4 + j * 4 + 2);
                    Union(UF, i * width * 4 + j * 4, i * width * 4 + j * 4 + 3);
                    if (i > 0)
                        Union(UF, (i - 1) * width * 4 + j * 4 + 2, i * width * 4 + j * 4);
                    if (j > 0)
                        Union(UF, i * width * 4 + j * 4 - 1, i * width * 4 + j * 4 + 1);
                }
                else
                {
                    Union(UF, i * width * 4 + j * 4 + 0, i * width * 4 + j * 4 + 1);
                    Union(UF, i * width * 4 + j * 4 + 1, i * width * 4 + j * 4 + 2);
                    Union(UF, i * width * 4 + j * 4 + 2, i * width * 4 + j * 4 + 3);
                    if (i > 0)
                        Union(UF, (i - 1) * width * 4 + j * 4 + 2, i * width * 4 + j * 4);
                    if (j > 0)
                        Union(UF, i * width * 4 + j * 4 - 1, i * width * 4 + j * 4 + 1);
                }
    		}
    	}
        unordered_set<int> set;
    	for(int i = 0;i<UF.size();i++)
    	{
            int tmp = Find(UF, i);
            if (set.find(tmp) == set.end())
                set.insert(tmp);
    	}
        return set.size();
    }
};

int main()
{
    Solution so;
    vector<string> strs = {" /", "  "};
    so.regionsBySlashes(strs);
}