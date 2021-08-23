/**
 * Author: Bao Wenjie
 * Date: 2021/3/4
 * Link: https://leetcode-cn.com/problems/russian-doll-envelopes/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace ::std;

bool cmp(const vector<int>& a, const vector<int>& b)
{
	if (a[0] < b[0])
		return true;
	else if (a[0] > b[0])
		return false;
	else
		return a[1] >= b[1];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end(), cmp);
		vector<int> dp(envelopes.size(), 1);
		for(int i = 0; i < envelopes.size(); i++)
		{
			int value = envelopes[i][1];
			int max_l = 0;
			for(int j = 0; j < i; j++)
			{
				if (envelopes[j][1] < value)
					max_l = max(max_l, dp[j]);
			}
			dp[i] = max_l + 1;
		}
		int max_l = 0;
		for (int i = 0; i < dp.size(); i++)
			max_l = max(max_l, dp[i]);
		return max_l;
    }
};