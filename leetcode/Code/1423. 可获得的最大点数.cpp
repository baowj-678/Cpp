/**
 * Author: Bao Wenjie
 * Date: 2021/1/26
 * Link: https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/
 */


#include <iostream>
#include <vector>

using namespace ::std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> prefix(cardPoints.size() + 1, 0);
        vector<int> suffix(cardPoints.size() + 1, 0);
        int maxPoints = 0;
    	for(int i = 0; i < cardPoints.size(); i++)
    	{
            prefix[i + 1] = prefix[i] + cardPoints[i];
            suffix[i + 1] = suffix[i] + cardPoints[cardPoints.size() - i - 1];
    	}
        if (k >= cardPoints.size())
            return prefix[cardPoints.size()];
    	for(int i = 0; i < prefix.size(), k - i >= 0; i++)
    	{
            int points = prefix[i] + suffix[k - i];
            maxPoints = max(maxPoints, points);
    	}
        return maxPoints;
    }
};