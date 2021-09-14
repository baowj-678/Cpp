/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
 * @date: 2021/9/14
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* cur = head;
        if (cur == NULL)
            return;
        if (cur->val == val)
            return cur->next;
    	while(cur->next && cur->next->val != val)
    	{
            cur = cur->next;
    	}
    	if(cur->next->val == val)
    	{
            cur->next = cur->next->next;
    	}
        return head;
    }
};