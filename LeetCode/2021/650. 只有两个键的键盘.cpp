/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/2-keys-keyboard/
 * @date: 2021/9/19
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        char isPrime[1005];
        memset(isPrime, 0, sizeof(isPrime));
        findPrime(isPrime, 1000);
        int subNum[20], len = 0;
    	for(int i = 2; i <= n; i++)
    	{
    		while(isPrime[i] == 0 && n % i == 0)
    		{
                subNum[len++] = i;
                n /= i;
    		}
    	}
        int ans = 0;
    	for(int i = 0; i < len; i++)
    	{
            ans += subNum[i];
    	}
        return ans - len + 1;
    }

	void findPrime(char* vec, int n)
    {
        vec[0] = vec[1] = 1;
    	for(int i = 2; i <= n; i++)
    	{
    		if(vec[i] == 1)
                continue;
    		for(int j = 2; i * j <= n; j++)
    		{
                vec[i * j] = 1;
    		}
    	}
    }
};