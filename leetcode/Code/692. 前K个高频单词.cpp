/**
 * @author: Bao Wenjie
 * @date: 2021/5/20
 * @link: https://leetcode-cn.com/problems/top-k-frequent-words/
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace::std;


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> word2num;
    	for(string word : words)
    	{
    		if(word2num.find(word) == word2num.end())
    		{
                word2num.insert(pair<string, int>(word, 1));
    		}
            else
            {
                word2num[word] += 1;
            }
    	}
        vector<string> s(word2num.size(), "");
        vector<int> nums(word2num.size(), 0);
        int i = 0;
    	for(auto a:word2num)
    	{
            s[i] = a.first;
            nums[i++] = a.second;
    	}
        sort(s, nums, 0, s.size(), k);
        vector<string> ans(k, "");
    	for(int i = 0; i < k; i++)
    	{
            ans[i] = s[i];
    	}
        return ans;
    }

	void sort(vector<string> &s, vector<int> &nums, int start, int end, int k)
    {
        if (start >= end - 1)
            return;
        int mid = (start + end) / 2;
        int val = nums[mid];
        swap(nums[end - 1], nums[mid]);
        swap(s[end - 1], s[mid]);
        int i = start, j = end - 2;
    	while(i < j)
    	{
    		while(i < j && nums[i] >= val)
    		{
                i++;
    		}
    		while(i < j && nums[j] < val)
    		{
                j--;
    		}
            swap(nums[i], nums[j]);
            swap(s[i], s[j]);
    	}
    	if(nums[j] >= nums[end - 1])
    	{
            swap(nums[end - 1], nums[j + 1]);
            swap(s[end - 1], s[j + 1]);
    	}
        else
        {
            swap(nums[end - 1], nums[j]);
            swap(s[end - 1], s[j]);
        }
        if (i + 1 >= k)
            sort(s, nums, start, i + 1, k);
        else
        {
            sort(s, nums, start, i + 1, k);
            sort(s, nums, i + 1, end, k);
        }
    }
};

int main()
{
    Solution solution;
    vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" };
    solution.topKFrequent(words, 2);
}