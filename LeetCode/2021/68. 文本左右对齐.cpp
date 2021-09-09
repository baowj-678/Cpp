/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/text-justification/
 * @date: 2021/9/9
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int begin = 0, width = 0;
    	for(int i = 0; i < words.size(); i++)
    	{
            width += words[i].size();
            int minWidth = width + (i - begin);
    		if(minWidth == maxWidth)
    		{
                string s;
    			for(int j = begin; j <= i; j++)
    			{
                    if (j > begin)
                        s += " ";
                    s += words[j];
    			}
                ans.push_back(s);
                begin = i + 1;
                width = 0;
    		}
            else if(minWidth > maxWidth)
            {
                width -= words[i].size();
                int end = i - 1;
                int avrNum = 0, leftNum = 0;
                if (end > begin)
                {
                    avrNum = (maxWidth - width) / (end - begin);
                    leftNum = maxWidth - width - (end - begin) * avrNum;
                }
                string s;
            	for(int j = begin; j <= end; j++)
            	{
                    if (j > begin)
                    {
                        if (j - begin <= leftNum)
                            for (int k = 0; k < avrNum + 1; k++)
                                s += " ";
                        else
                            for (int k = 0; k < avrNum; k++)
                                s += " ";
                    }
                    s += words[j];
            	}
                while (s.size() < maxWidth)
                    s += " ";
                ans.push_back(s);
                begin = i;
                width = words[i].size();
            }
    	}
    	if(begin < words.size())
    	{
            string s;
    		for(int i = begin; i < words.size(); i++)
    		{
                if (i > begin)
                    s += " ";
                s += words[i];
    		}
            while (s.size() < maxWidth)
                s += " ";
            ans.push_back(s);
    	}
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<string> vec = { "This", "is", "an", "example", "of", "text", "justification." };
    solution.fullJustify(vec, 16);
}