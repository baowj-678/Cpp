/**
 * Author: Bao Wenjie
 * Date: 2021/3/25
 * Link: https://leetcode-cn.com/problems/jump-game-v/
 */

#include <iostream>
#include <vector>

using namespace::std;


class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
    	vector<int> dp(arr.size(), -1);
    	int maxJ = 0;
    	for(int i = 0; i < arr.size(); i++)
    	{
    		getMaxJumps(arr, dp, i, d);
    		maxJ = max(maxJ, dp[i]);
		}
		return maxJ;
    }
    
    int getMaxJumps(vector<int>& arr, vector<int>& dp, int p, int d)
    {
    	if(dp[p] != -1)
    		return dp[p];
    	int height = arr[p];
    	int maxJ = 1;
    	for(int j = p - 1; j >= 0 && p - j <= d; j--)
    	{
    		if(arr[j] >= height)
    			break;
    		maxJ = max(maxJ, getMaxJumps(arr, dp, j, d) + 1);
		}
    	for(int i = p + 1; i < arr.size() && i - p <= d; i++)
    	{
    		if(arr[i] >= height)
    			break;
    		maxJ = max(maxJ, getMaxJumps(arr, dp, i, d) + 1);
		}
		dp[p] = maxJ;
		return maxJ;
	}
};


int main()
{
	vector<int> arr = {6,4,14,6,8,13,9,7,10,6,12};
	Solution solution;
	cout << solution.maxJumps(arr, 2);
}
