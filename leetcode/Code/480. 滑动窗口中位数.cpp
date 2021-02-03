/**
 * Author: Bao Wenjie
 * Date: 2021/2/3
 * Link: https://leetcode-cn.com/problems/sliding-window-median/
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace ::std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans(nums.size() - k + 1, 0);
        vector<int> window(k, 0);
    	for(int i = 0; i < k; i++)
    	{
            window[i] = nums[i];
    	}
        sort(window.begin(), window.end());
        int p = 0;
        int half_k = k / 2;
        bool is_odd = true;
    	if(k % 2 == 0)
    	{
            is_odd = false;
    	}
    	if(is_odd)
    	{
            ans[p++] = window[half_k];
    	}
        else
        {
            ans[p++] = ((double)window[half_k] + window[half_k - 1]) / 2;
        }
    	
    	for(int i = k; i < nums.size(); i++)
    	{
            int add_num = nums[i];
            int remove_num = nums[i - k];
            int left = 0, right = k - 1, half;
    		
    		while(left < right)
    		{
                half = (left + right) / 2;
    			if(window[half] > remove_num)
    			{
                    right = half;
    			}
                else if(window[half] < remove_num)
                {
                    left = half + 1;
                }
                else
                {
                    left = right = half;
                }
    		}
            half = left;
    		if(add_num > remove_num)
    		{
    			while(half + 1 < k)
    			{
    				if(window[half + 1] >= add_num)
    				{
                        window[half] = add_num;
                        break;
    				}
                    else
                    {
                        window[half] = window[half + 1];
                    }
                    half++;
    			}
    			if(half + 1 == k)
    			{
                    window[k - 1] = add_num;
    			}
    		}
            else
            {
                while (half > 0)
                {
                    if (window[half - 1] <= add_num)
                    {
                        window[half] = add_num;
                        break;
                    }
                    else
                    {
                        window[half] = window[half - 1];
                    }
                    half--;
                }
                if (half == 0)
                {
                    window[0] = add_num;
                }
            }
            if (is_odd)
            {
                ans[p++] = window[half_k];
            }
            else
            {
                ans[p++] = ((double)window[half_k] + window[half_k - 1]) / 2;
            }
    	}
        return ans;
    }
};

int main()
{
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    Solution so;
    so.medianSlidingWindow(nums, 3);
}