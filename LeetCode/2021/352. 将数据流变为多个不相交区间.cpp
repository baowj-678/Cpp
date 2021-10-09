/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals/
 * @date: 2021/10/9
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class SummaryRanges {
private:
    map<int, int> intervals;

public:
    SummaryRanges() {}

    void addNum(int val) {
        auto interval1 = intervals.upper_bound(val);
        auto interval0 = (interval1 == intervals.begin() ? intervals.end() : prev(interval1));

        if (interval0 != intervals.end() && interval0->first <= val && val <= interval0->second) {
            // 情况一
            return;
        }
        else {
            bool left_aside = (interval0 != intervals.end() && interval0->second + 1 == val);
            bool right_aside = (interval1 != intervals.end() && interval1->first - 1 == val);
            if (left_aside && right_aside) {
                // 情况四
                int left = interval0->first, right = interval1->second;
                intervals.erase(interval0);
                intervals.erase(interval1);
                intervals.emplace(left, right);
            }
            else if (left_aside) {
                // 情况二
                ++interval0->second;
            }
            else if (right_aside) {
                // 情况三
                int right = interval1->second;
                intervals.erase(interval1);
                intervals.emplace(val, right);
            }
            else {
                // 情况五
                intervals.emplace(val, val);
            }
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        map<int, int>::iterator iter = intervals.begin();
    	while(iter != intervals.end())
    	{
            ans.push_back({ iter->first, iter->second });
    	}
        return ans;
    }
};

int main()
{
    map<int, int> a;
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
