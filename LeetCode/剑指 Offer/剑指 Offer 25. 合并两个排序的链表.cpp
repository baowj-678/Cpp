/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
 * @date: 2021/9/19
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head, *tail;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val > l2->val)
        {
            tail = head = l2;
            l2 = l2->next;
        }
        else
        {
            tail = head = l1;
            l1 = l1->next;
        }
    	while(l1 && l2)
    	{
    		if(l1->val < l2->val)
    		{
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
    		}
            else
            {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
    	}
        if (l1)
            tail->next = l1;
        if (l2)
            tail->next = l2;
        return head;
    }
};