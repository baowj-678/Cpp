/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
 * @date: 2021/9/13
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int showTimes[256];
        memset(showTimes, 0, sizeof(showTimes));
        int leftP = 0, rightP = 0, maxLen = 0;
    	for(rightP = 0; rightP < s.length(); rightP ++)
    	{
            char c = s[rightP];
            showTimes[c] ++;
    		if(showTimes[c] > 1)
    		{
                maxLen = max(maxLen, rightP - leftP);
    			while(showTimes[c] > 1)
    			{
                    showTimes[s[leftP++]]--;
    			}
    		}
            else
            {
                maxLen = max(maxLen, rightP - leftP);
            }
    	}
        maxLen = max(maxLen, rightP - leftP);;
        return maxLen;
    }
};