/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
 * @date: 2021/10/10
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        kSort(arr, 0, arr.size() - 1, k);
        arr.resize(k);
        return arr;
    }

	void kSort(vector<int> & arr, int left, int right, int k)
    {
        if (right - left < 1)
            return;
        if (arr[left] > arr[right])
            swap(arr[left], arr[right]);
        int val = arr[right];
        int i_left = left, i_right = right - 1;
    	
    	while(i_left < i_right)
    	{
            while (i_left < right && arr[i_left] <= val)
                i_left++;
            while (arr[i_right] > val)
                i_right--;
            if (i_left < i_right)
                swap(arr[i_left], arr[i_right]);
    	}
        if (arr[i_left] > arr[right])
            swap(arr[i_left], arr[right]);
        if (i_left + 1 == k)
            return;
        else if(i_left + 1 < k)
        {
            kSort(arr, i_left + 1, right, k);
        }
        else if(i_left + 1 > k)
        {
            kSort(arr, left, i_left - 1, k);
        }
    }
};

int main()
{
    Solution solution;
    vector<int> arr = { 0,1,2,1 };
    solution.getLeastNumbers(arr, 1);
}