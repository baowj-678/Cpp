/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/string-compression/
 * @date: 2021/8/21
 */
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int compress(vector<char>& chars) {
        char last = -1;
        char nums[10];
        int cnt = 0, last_cnt = 0;
        int p2 = 0;
        for(int p1 = 0; p1 < chars.size(); p1++)
        {
            char c = chars[p1];
	        if(last == c)
	        {
                last_cnt++;
	        }
            else
            {
            	if(last_cnt > 1)
            	{
                    subF(chars, p2, last_cnt);
            	}
                last = c;
                chars[p2++] = c;
                last_cnt = 1;
            }
        }
        if (last_cnt > 1)
        {
            subF(chars, p2, last_cnt);
        }
        return p2;
    }

	int subF(vector<char>& vec, int& cur, int value)
    {
	    if(value > 0)
	    {
            char tmp = value % 10;
            value /= 10;
            int len = subF(vec, cur, value);
            vec[cur++] = tmp + '0';
            return len + 1;
	    }
        return 0;
    }
};


int main()
{
    vector<char> vec = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    Solution solutions;
    cout << solutions.compress(vec);
}