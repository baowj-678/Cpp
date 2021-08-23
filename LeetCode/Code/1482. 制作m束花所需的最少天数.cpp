/**
 * @author: Bao Wenjie
 * @date: 2021/5/9
 * @link: https://leetcode-cn.com/problems/minimum-number-of-days-to-make-m-bouquets/
 */

#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int minn = INT_MAX, maxx = INT_MIN;
        if(m * k > bloomDay.size())
            return -1;
        for(int i = 0; i < bloomDay.size(); i++)
        {
            minn = min(minn, bloomDay[i]);
            maxx = max(maxx, bloomDay[i]);
        }
        while(minn < maxx)
        {
            int mid = (maxx + minn)/2;
            int n = 0, k_ = 0;
            bool isLastOK = false;
            for(int i = 0; i < bloomDay.size(); i++)
            {
                if(bloomDay[i] <= mid)
                {
                    if(isLastOK)
                    {
                        k_++;
                    }
                    else
                    {
                        k_ = 1;
                        isLastOK = true;
                    }
                }
                else
                {
                    isLastOK = false;
                }
                if (k_ >= k)
                {
                    k_ = 0;
                    n++;
                }
                if(n >= m)
                    break;
            }
            if(n >= m)
            {
                maxx = mid;
            }
            else
            {
                minn = mid + 1;
            }
        }
        return minn;
    }
};

int main()
{
    Solution solution;
    vector<int>a = { 1,10,3,10,2 };

    cout << solution.minDays(a, 3, 1);
}