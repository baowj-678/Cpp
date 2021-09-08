/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
 * @date: 2021/9/8
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;
        if (numbers[left] < numbers[right])
            return numbers[left];
    	while(left < right)
    	{
            int mid = (left + right) / 2;
            if (numbers[mid] > numbers[right])
            {
                left = mid + 1;
            }
            else if (numbers[mid] < numbers[right])
            {
                right = mid;
            }
            else
                right--;
    	}
        return numbers[left];
    }
};