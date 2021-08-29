/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/find-median-from-data-stream/
 * @date: 2021/8/28
 */
#include <iostream>
#include <queue>
using namespace::std;

class MedianFinder {
public:

    priority_queue<int, vector<int>, greater<int>> queMax;
    priority_queue<int, vector<int>, less<int>> queMin;
    /** initialize your data structure here. */
    MedianFinder() {
    	
    }

    void addNum(int num) {
        if (this->queMax.size() == 0)
            this->queMax.push(num);
        else if(this->queMin.size() == 0)
        {
            int max_ = queMax.top();
        	if(max_ < num)
        	{
                queMax.pop();
                queMax.push(num);
                queMin.push(max_);
        	}
            else
            {
                queMin.push(num);
            }
        }
        else
        {
            int max_ = queMax.top(), min_ = queMin.top();
        	if(num > max_)
        	{
                queMax.pop();
                queMax.push(num);
                num = max_;
        	}
            else if(num < min_)
            {
                queMin.pop();
                queMin.push(num);
                num = min_;
            }
            if (queMax.size() <= queMin.size())
                queMax.push(num);
            else
                queMin.push(num);
        }
    }

    double findMedian() {
        if ((queMax.size() + queMin.size()) % 2 == 1)
            return queMax.top();
        else return ((static_cast<double>(queMax.top())) + queMin.top()) / 2;
    }
};

int main()
{
    MedianFinder median_finder;
    priority_queue<int, vector<int>, less<int>> a;
    a.push(1);
    a.push(2);
    a.push(4);
    while (a.size() > 0)
    {
        cout << a.top() << " ";
        a.pop();
    }
}