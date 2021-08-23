/**
 * Author: Bao Wenjie
 * Date: 2021/2/1
 * Link: https://leetcode-cn.com/problems/decoded-string-at-index/
 */
#include <iostream>
#include <string>

using namespace ::std;

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long sum = 0;
    	for(char c:S)
    	{
            if ('a' <= c && c <= 'z')
                sum += 1;
            else if ('2' <= c && c <= '9')
                sum *= (c - '0');
    	}
    	
    	for(int i = S.length() - 1; i >= 0; i--)
    	{
    		if(isalpha(S[i]))
    		{
    			if(K == sum)
    			{
                    return S.substr(i, 1);
    			}
                sum--;
    		}
            else
            {
                int t = S[i] - '0';
                sum /= t;
                if (sum < K)
                {
                    K %= sum;
                    if (K == 0)
                        K = sum;
                }
            }
    	}
        return "";
    }
};


int main()
{
    string str = "leet2code3";
    int K = 36;
    Solution so;
    so.decodeAtIndex(str, K);
}