/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/random-pick-with-weight/\
 * @date: 2021/8/30
 */

#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    vector<int> W;
    Solution(vector<int>& w) {
        W = w;
        for(int i = 1; i < W.size(); i++)
        {
            W[i] += W[i - 1];
        }
    }

    int pickIndex() {
        int index = rand() % W[W.size() - 1];
        int left = 0, right = W.size() - 1;
    	while(left < right)
    	{
            int mid = (left + right) / 2;
            if (index >= W[mid])
            {
                left = mid + 1;
            }
            else
                right = mid;
    	}
        return left;
    }
};


int main()
{
    for (int i = 1; i <= 10; i++)
        cout << rand() << endl;;
}
