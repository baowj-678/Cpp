/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/compare-version-numbers/
 * @date: 2021/9/1
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p_1 = 0, p_2 = 0;
    	while(p_1 < version1.length() || p_2 < version2.length())
    	{
            int n_1, n_2;
            if (p_1 >= version1.length())
                n_1 = 0;
            else
            {
                int p_1_ = p_1;
            	if(version1[p_1] == '.')
            	{
                    p_1++;
                    p_1_++;
            	}
                while (p_1 < version1.length() && version1[p_1] != '.')
                    p_1++;
                n_1 = atoi(version1.substr(p_1_, p_1 - p_1_).c_str());
            }
            if (p_2 >= version2.length())
                n_2 = 0;
            else
            {
                int p_2_ = p_2;
            	if(version2[p_2] == '.')
            	{
                    p_2++;
                    p_2_++;
            	}
                while (p_2 < version2.length() && version2[p_2] != '.')
                    p_2++;
                n_2 = atoi(version2.substr(p_2_, p_2 - p_2_).c_str());
            }
            if (n_1 < n_2)
                return -1;
            else if (n_1 > n_2)
                return 1;
    	}
        return 0;
    }
};

int main()
{
    string s1 = "1.01", s2 = "1.0.01";
    Solution solution;
    solution.compareVersion(s1, s2);
}