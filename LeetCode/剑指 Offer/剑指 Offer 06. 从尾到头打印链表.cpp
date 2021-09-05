/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
 * @date: 2021/9/5
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
    	while(head != NULL)
    	{
            ans.push_back(head->val);
            head = head->next;
    	}
        int i = 0, j = ans.size() - 1;
    	while(i < j)
    	{
            swap(ans[i++], ans[j--]);
    	}
        return ans;
    }
};