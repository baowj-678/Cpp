/**
 * Author: Bao Wenjie
 * Date: 2021/4/21
 * Link: https://leetcode-cn.com/problems/decode-ways/
 */

#include <iostream>
#include <vector>

using namespace ::std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> vec(s.size(), 0);
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] != 0)
            {
                vec[i] = (i - 1 >= 0) ? vec[i - 1] : 1;
            }

            if(i - 1 >= 0)
            {
                if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
                {
                    vec[i] += (i - 2 >= 0) ? vec[i - 2] : 1;
                }
            }
        }
        return vec[vec.size() - 1];
    }
};

int main()
{
    string s = "102";
    Solution solution;
    cout << solution.numDecodings(s);
}
