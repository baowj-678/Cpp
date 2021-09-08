/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/ipo/
 * @date: 2021/9/8
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int, vector<int>, less<int>> pq;
        vector<pair<int, int>> arr;
        int cur = 0;
    	for(int i = 0; i < profits.size(); i++)
    	{
            arr.push_back({ capital[i], profits[i] });
    	}
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; i++)
        {
            while (cur < profits.size() && arr[cur].first <= w)
            {
                pq.push(arr[cur].second);
                cur++;
            }
            if (!pq.empty())
            {
                w += pq.top();
                pq.pop();
            }
            else
                break;
        }
        return w;
    }
};