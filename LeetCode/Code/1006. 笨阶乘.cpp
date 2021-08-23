/**
 * Author: Bao Wenjie
 * Date: 2021/4/1 
 * Link: https://leetcode-cn.com/problems/clumsy-factorial/
 */
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int clumsy(int N) {
    	int sum = 0;
    	if(N >= 3)
    		sum = N * (N-1) / (N-2);
    	else if(N == 2)
    		return N * (N-1);
    	else if (N == 1)
    		return N;
    	N -= 3;
    	int cnt = 0, tmp_b = 0, tmp_a = 0;
    	for(int i = N; i > 0; i--)
    	{
    		switch (cnt)
    		{
    			case 0:
    				tmp_b = i;
    				cnt ++;
    				break;
    			case 1:
    				tmp_a = i;
    				cnt ++;
    				break;
    			case 2:
    				tmp_a *= i;
    				cnt ++;
    				break;
    			case 3:
    				tmp_a /= i;
    				cnt = 0;
    				sum += (tmp_b - tmp_a);
    				tmp_b = 0;
    				break;
			}
		}
		if(N % 4 != 0)
		{
			sum += (tmp_b - tmp_a);
		}
		return sum;
    }
};
