/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/escape-the-ghosts/
 * @date: 2021/8/22
 */
#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int min_ = abs(target[0]) + abs(target[1]);
    	for(vector<int>& ghost : ghosts)
    	{
            if (abs(target[0] - ghost[0]) + abs(target[1] - ghost[1]) <= min_)
                return false;
    	}
        return true;
    }
};