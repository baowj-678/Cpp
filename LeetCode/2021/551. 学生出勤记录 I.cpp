/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/student-attendance-record-i/
 * @date: 2021/8/20
 */
#include <iostream>
#include <string>
using namespace::std;


class Solution {
public:
    bool checkRecord(string s) {
        int cnt_a = 0, cnt_l = 0;
    	for(char c : s)
    	{
            if (c == 'A')
            {
                cnt_a++;
                if (cnt_l < 3)
                    cnt_l = 0;
            }
            else if(c == 'L')
            {
                if (cnt_l == 0)
                    cnt_l = 1;
                else
                    cnt_l++;
            }
            else
            {
                if (cnt_l < 3)
                    cnt_l = 0;
            }
    	}
        if (cnt_a < 2 && cnt_l < 3)
            return true;
        return false;
    }
};