/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/boats-to-save-people/
 * @date: 2021/8/27
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), greater<int>());
        int left = 0, right = people.size() - 1;
        int cnt = 0;
    	while(left < right)
    	{
    		if(people[left] + people[right] <= limit)
    		{
                cnt++;
                left++;
                right--;
    		}
            else if(people[left] <= limit)
            {
                cnt++;
                left++;
            }
            else
            {
                return -1;
            }
    	}
    	if(left == right)
    	{
            if (people[left] <= limit)
                cnt++;
            else
                return -1;
    	}
        return cnt;
    }
};

int main()
{
    vector<int> tmp = { 3,2,2,1 };
    Solution solution;
    cout << solution.numRescueBoats(tmp, 3);
}