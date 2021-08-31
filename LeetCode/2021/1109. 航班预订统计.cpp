/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/corporate-flight-bookings/
 * @date: 2021/8/31
 */
#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
    	for(vector<int>& book : bookings)
    	{
            ans[book[0] - 1] += book[2];
            if (book[1] < n)
                ans[book[1]] -= book[2];
    	}
    	for(int i = 1; i < n; i++)
    	{
            ans[i] += ans[i - 1];
    	}
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> bookings = { {1, 2, 10},{2, 3, 20},{2, 5, 25} };
    solution.corpFlightBookings(bookings, 5);
}