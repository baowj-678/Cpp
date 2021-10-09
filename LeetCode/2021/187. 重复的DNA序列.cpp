/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/repeated-dna-sequences/
 * @date: 2021/10/8
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int S[1024 * 1024 + 50];

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        memset(S, 0, sizeof(S));
        vector<string> ans;
        int num = 0;
        if (s.length() <= 10)
            return ans;
    	for(int i = 0; i < 10; i++)
    	{
    		if(s[i] == 'A')
    		{
                num = (num << 2) | 0b00;
    		}
            else if(s[i] == 'C')
            {
                num = (num << 2) | 0b01;
            }
            else if(s[i] == 'G')
            {
                num = (num << 2) | 0b10;
            }
            else
            {
                num = (num << 2) | 0b11;
            }
    	}
        S[num] = 1;
    	for(int i = 10; i < s.length(); i++)
    	{
            num &= (~(0b11 << 18));
            if (s[i] == 'A')
            {
                num = (num << 2) | 0b00;
            }
            else if (s[i] == 'C')
            {
                num = (num << 2) | 0b01;
            }
            else if (s[i] == 'G')
            {
                num = (num << 2) | 0b10;
            }
            else
            {
                num = (num << 2) | 0b11;
            }
    		if(S[num] == 1)
    		{
                ans.push_back(s.substr(i - 10 + 1, 10));
    		}
            S[num]++;
    	}
        return ans;
    }
};

int main()
{
    Solution solution;
    string s ("AAAAACCCCCAAAAACCCCCCAAAAAGGGTT");
    solution.findRepeatedDnaSequences(s);
}