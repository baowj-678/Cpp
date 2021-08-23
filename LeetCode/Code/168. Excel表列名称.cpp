/**
 * @author: Bao Wenjie
 * @date: 2021/6/29
 * @link: https://leetcode-cn.com/problems/excel-sheet-column-title/
 */
#include <iostream>
#include <string>

using namespace::std;


class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s;
    	while(columnNumber > 0)
    	{
            int num = columnNumber % 26;
            int sub = 0;
            if (num == 0)
            {
                num = 26;
                sub = 1;
            }
            columnNumber /= 26;
            columnNumber -= sub;
            char c = 'A' + num - 1;
            s.insert(0, 1, c);
    	}
        return s;
    }
};

int main()
{
    Solution solution;
    cout << solution.convertToTitle(2147483647);
}