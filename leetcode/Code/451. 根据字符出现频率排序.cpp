/**
 * @author: Bao Wenjie
 * @date: 2021/7/3
 * @link: https://leetcode-cn.com/problems/sort-characters-by-frequency/
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

typedef struct char_num
{
    int c;
    int num;
}char_num;

bool cmp(char_num& a, char_num& b)
{
    return a.num > b.num;
}

class Solution {
public:
    string frequencySort(string s) {
        char_num vec[256];
    	for(int i = 0; i < 256; i++)
    	{
            vec[i].c = i;
            vec[i].num = 0;
    	}
    	for(auto x:s)
    	{
            vec[x].num++;
    	}
        sort(vec, vec + 256, cmp);
        int k = 0;
    	for(int i = 0; i < 256; i++)
    	{
    		while(vec[i].num > 0)
    		{
                s[k++] = vec[i].c;
                vec[i].num--;
    		}
    	}
        return s;
    }
};

int main()
{
    Solution solution;
    cout << solution.frequencySort("tree");
}