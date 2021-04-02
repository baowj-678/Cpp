/**
 * Author: Bao Wenjie
 * Date: 2021/4/2
 * Link: https://leetcode-cn.com/problems/volume-of-histogram-lcci/
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace::std;
 
class Solution {
public:
    int trap(vector<int>& height) {
    	stack<pair<int, int> > down;
    	int sum = 0;
    	for(int i = 0; i < height.size(); i++)
    	{
    		if(down.empty())
    		{
    			down.push({i, height[i]});
    			continue;
			}
			int height_last = 0, height_now = height[i];
			pair<int, int> tmp = down.top();
			while(tmp.second <= height_now)
			{
				down.pop();
				sum += (i - tmp.first - 1) * (tmp.second - height_last);
				height_last = tmp.second;
				if(down.empty())
					break;
				tmp = down.top();
			}
			if(!down.empty())
				sum += (i - tmp.first - 1) * (min(tmp.second, height_now) - height_last);
			down.push({i, height[i]});
		}
		return sum;
    }
};

int main()
{
	int a[] = {3,4,5};
	vector<int> height(a, a+sizeof(a)/4);
	Solution solution;
	cout << solution.trap(height);
}
