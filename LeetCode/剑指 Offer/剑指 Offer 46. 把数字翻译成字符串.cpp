/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
 * @date: 2021/9/13
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        int dp[20];
        string s = to_string(num);
        const char* str = s.c_str();
        memset(dp, 0, sizeof(dp));
        int n = strlen(str);
    	for(int i = 0; i < n; i++)
    	{
            if (i > 0)
                dp[i] += dp[i - 1];
            else
                dp[i] = 1;

    		if(i > 1)
    		{
    			if(str[i - 1] != '0')
    			{
                    int tmp = (str[i - 1] - '0') * 10 + (str[i] - '0');
    				if(tmp >= 0 && tmp <= 25)
    				{
                        dp[i] += dp[i - 2];
    				}
    			}
    		}
            else if(i == 1)
            {
                if (str[i - 1] != '0')
                {
                    int tmp = (str[i - 1] - '0') * 10 + (str[i] - '0');
                    if (tmp >= 0 && tmp <= 25)
                    {
                        dp[i] += 1;
                    }
                }
            }
    	}
        return dp[n - 1];
    }
};

int main()
{
    Solution solution;
    cout << solution.translateNum(2001001);
}