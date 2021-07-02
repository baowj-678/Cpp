/**
 * @author: Bao Wenjie
 * @date: 2021/7/2
 * @link: https://leetcode-cn.com/problems/maximum-ice-cream-bars/
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

bool cmp(int a, int b)
{
    return a < b;
}

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end(), cmp);
        int cnt = 0;
    	for(int i = 0; i < costs.size(); i++)
    	{
    		if(coins < costs[i])
    		{
    			break;
    		}
            coins -= costs[i];
            cnt++;
    	}
        return cnt;
    }
};