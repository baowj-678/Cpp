/**
 * Author: Bao Wenjie
 * Date: 2021/4/3 
 * Link: https://leetcode-cn.com/problems/find-latest-group-of-size-m/
 */

#include <iostream>
#include <vector>

using namespace::std;


class Solution {
public:
	void Union(vector<int>& parents, vector<int>& nums, int a, int b)
	{
		a = Find(parents, a);
		b = Find(parents, b);
		parents[b] = a;
		nums[a] += nums[b];
	}
	
	int Find(vector<int>& parents, int a)
	{
		int x = a;
		while(a != parents[a])
		{
			a = parents[a];
		}
		while(x != a)
		{
			int tmp = parents[x];
			parents[x] = a;
			x = tmp;
		}
		return a;
	}
	
    int findLatestStep(vector<int>& arr, int m) {
    	int cnt = 0, index = -1;
    	vector<int> parents(arr.size(), 0);
    	vector<int> is_zero(arr.size(), 0);
    	vector<int> nums(arr.size(), 1);
    	for(int i = 0; i < arr.size(); i++)
    		parents[i] = i;
    	for(int i = 0; i < arr.size(); i++)
    	{
    		int x = arr[i];
			is_zero[x-1] = 1;
    		if(x > 1 && (is_zero[x-2] == 1))
    		{
    			if(nums[Find(parents, x-2)] == m)
    			{
    				cnt--;
				}
    			Union(parents, nums, x-1, x-2);
			}
			if(x < parents.size() && (is_zero[x] == 1))
			{
				if(nums[Find(parents, x)] == m)
    			{
    				cnt--;
				}
				Union(parents, nums, x-1, x);
			}
			if(nums[Find(parents, x-1)] == m)
			{
				cnt++;
			}
			if(cnt > 0)
				index = i; 
		}
		return index == -1 ? -1 : index + 1;
    }
};
