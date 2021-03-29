/**
 * Author: Bao Wenjie
 * Date: 2021/3/29
 * Link: https://leetcode-cn.com/problems/ipo/
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace ::std;


struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.second < b.second)
            return false;
        else if (a.second > b.second)
            return true;
        else
            return a.first < b.first;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> fit;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> not_fit;
    	for(int i = 0; i < Profits.size(); i++)
    	{
    		if(Capital[i] <= W)
    		{
                fit.push({ Profits[i], Capital[i] });
    		}
            else
            {
                not_fit.push({ Profits[i], Capital[i] });
            }
    	}
        int profit_sum = W;
    	for(int i = 0; i < k; i++)
    	{
    		if(fit.size() > 0)
    		{
                pair<int, int> tmp = fit.top();
                fit.pop();
                profit_sum += tmp.first;
    		}
    		while(not_fit.size() > 0)
    		{
                pair<int, int> tmp = not_fit.top();
    			if(tmp.second <= profit_sum)
    			{
                    fit.push(tmp);
                    not_fit.pop();
    			}
                else
                {
                    break;
                }
    		}
    	}
        return profit_sum;
    }
};

int main()
{
    Solution solution;
    vector<int> Profits = { 1,2,3 };
    vector<int> Capital = { 0,1,2 };
    cout << solution.findMaximizedCapital(3, 0, Profits, Capital);
}