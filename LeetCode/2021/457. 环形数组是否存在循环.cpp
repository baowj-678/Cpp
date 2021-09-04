/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/circular-array-loop/
 * @date: 2021/9/4
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
    	for(int i = 0; i < nums.size(); i++)
    	{
    		if(nums[i] > 1000)
                continue;
            int cur = i;
            int cnt = 0;
    		while(nums[cur] > 0)
    		{
                cnt++;
                if (nums[cur] > 1000)
                {
                    if (nums[cur] == 1000 + i + 1 && cnt > 2)
                        return true;
                	break;
                }
                int tmp = (nums[cur] + cur) % nums.size();
                nums[cur] = i + 1000 + 1;
                cur = tmp;
    		}
    	}
        for (int i = nums.size() - 1; i >= 0; i++)
        {
            if (nums[i] < -1000)
                continue;
            int cur = i, cnt = 0;
            while (nums[cur] < 0)
            {
                cnt++;
                if (nums[cur] < -1000)
                {
                    if (nums[cur] == -1000 - i - 1 && cnt > 2)
                        return true;
                    break;
                }
                int tmp = (nums[cur] + cur >= 0) ? ((nums[cur] + cur) % nums.size()) : ((nums[cur] + cur - 1) % nums.size());
                nums[cur] = -i - 1 - 1000;
                cur = tmp;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> vec = { 2, 2, 2, 2, 2, 4, 7 };
    solution.circularArrayLoop(vec);
}