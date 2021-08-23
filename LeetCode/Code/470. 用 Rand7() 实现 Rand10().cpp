/**
 * Author: Bao Wenjie
 * Date: 2021/3/14
 * Link: https://leetcode-cn.com/problems/implement-rand10-using-rand7/
 */


// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

#include <iostream>


using namespace::std;
class Solution {
public:
    int rand10() {
    	int res;
        while(true)
        {
        	res = (rand7() - 1) * 7 + rand(7);
        	if(res <= 40)
        		break;
		}
		return res % 10 + 1;
    }
};
