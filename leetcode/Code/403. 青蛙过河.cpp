/**
 * @author Bao Wenjie
 * @date 2021/4/30
 * @link https://leetcode-cn.com/problems/frog-jump/
 */

#include <iostream>
#include <vector>
#include <set>
using namespace ::std;


class Solution {
public:
    bool canCross(vector<int>& stones) {
        vector<set<int>> vec(stones.size(), set<int>());
        if(stones[1] == 1)
        {
            vec[1].emplace(1);
        }
        else
        {
            return false;
        }
    	for(int i = 2; i < stones.size(); i++)
    	{
            int i_p = stones[i];
    		for(int j = i - 1; j >= 1; j--)
    		{
                int j_p = stones[j];
                if (i_p - j_p > j + 1)
                    break;
    			for(auto x:vec[j])
    			{
    				if(abs(i_p - j_p - x) <= 1)
    				{
                        vec[i].emplace(i_p - j_p);
    				}
    			}
    		}
    	}
        if (vec[vec.size() - 1].size() > 0)
            return true;
        else
            return false;
    }
};