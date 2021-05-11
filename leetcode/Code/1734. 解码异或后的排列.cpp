/**
* @author: Bao Wenjie
* @date: 2021/5/11
* @link: https://leetcode-cn.com/problems/decode-xored-permutation/
*/

#include <iostream>
#include <vector>

using namespace::std;
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int total = encoded.size(), odd = 0;
        vector<int>ans(encoded.size() + 1, 0);
        total ^= (total + 1);
        for (int i = 0; i < encoded.size(); i++)
        {
            total ^= i;
            if (i % 2 == 1)
                odd ^= encoded[i];
            if (i > 0)
                ans[i] = ans[i - 1] ^ encoded[i - 1];
        }
        ans[encoded.size()] = ans[encoded.size() - 1] ^ encoded[encoded.size() - 1];
        int tmp = total ^ odd;
        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] ^= tmp;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int>a = { 3,1 };
    solution.decode(a);
}