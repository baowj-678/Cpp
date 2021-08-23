/**
 * Author: Bao Wenjie
 * Date: 2021/4/4 
 * Link: https://leetcode-cn.com/problems/rabbits-in-forest/
 */
#include <iostream>
#include <vector>
#include <map>

using namespace::std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
    	map<int, int> n2t;
    	for(int x:answers)
    	{
    		if(n2t.find(x) != n2t.end())
    		{
    			n2t[x]++;
			}
			else
			{
				n2t[x] = 1;
			}
		}
		int sum = 0;
		map<int, int>::iterator itor;
		for(itor = n2t.begin(); itor != n2t.end(); itor++)
		{
			int n = itor->second/(itor->first+1);
			if(itor->second-(itor->first + 1)*n > 0)
				n += 1;
			sum += (itor->first+1) * n;
		}
		return sum;
    }
}; 
