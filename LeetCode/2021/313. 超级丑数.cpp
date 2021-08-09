/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/super-ugly-number/
 * @date: 2021/8/9
 */

#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> vec(n + 5, 0);
        vec[0] = 1;
        vector<int> pointer(primes.size(), 0);
    	for(int i = 1; i < n; i++)
    	{
            while (true)
            {
                long long min_ = LONG_MAX;
                int index = 0;
                for (int j = 0; j < primes.size(); j++)
                {
                    long long tmp = static_cast<long long>(vec[pointer[j]]) * static_cast<long long>(primes[j]);
                	if(tmp < min_)
                	{
                        min_ = tmp;
                        index = j;
                	}
                }
                pointer[index]++;
            	if(min_ > vec[i-1])
            	{
                    vec[i] = min_;
            		break;
            	}
            }
    	}
        return vec[n - 1];
    }
};

int main()
{
    Solution solution;
    vector<int>primes = { 2,7,13,19 };
    cout << solution.nthSuperUglyNumber(12, primes);
}