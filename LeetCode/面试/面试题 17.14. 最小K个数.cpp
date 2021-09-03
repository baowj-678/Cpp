/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/smallest-k-lcci/
 * @date: 2021/9/3
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        qSort(arr, 0, arr.size() - 1, k);
        vector<int>  ans(k, 0);
        for (int i = 0; i < k; i++)
            ans[i] = arr[i];
        return ans;
    }

	void qSort(vector<int>& arr, int begin, int end, int k)
    {
        if (begin == end || k <= begin || k >= end)
            return;
        int mid = (begin + end) / 2;
    	if(arr[begin] > arr[mid])
            swap(arr[begin], arr[mid]);
    	if(arr[begin] > arr[end])
            swap(arr[begin], arr[end]);
        if (arr[mid] > arr[end])
            swap(arr[mid], arr[end]);
        swap(arr[mid], arr[end - 1]);
        int pivot = arr[end - 1];
        int left = begin, right = end - 1;
    	while(left < right)
    	{
            while (left < end - 1 && arr[left] <= pivot)
                left++;
            while (right > begin && arr[right] > pivot)
                right--;
    		if(left < right)
				swap(arr[left], arr[right]);
    	}
        swap(arr[left], arr[end - 1]);
        if (left < k - 1)
            qSort(arr, left, end, k);
        else if (left > k - 1)
            qSort(arr, begin, left, k);
        else
            return;
    }
};

int main()
{
    Solution solution;
    vector<int> arr = { 1, 3, 5, 7, 2, 4, 6, 8 };
    solution.smallestK(arr, 4);
}