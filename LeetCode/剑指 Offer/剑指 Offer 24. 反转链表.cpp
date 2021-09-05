/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/
 * @date: 2021/9/5
 */
#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* second = NULL, *third;
    	while(head != NULL)
    	{
            third = head;
            head = head->next;
            third->next = second;
            second = third;
    	}
        return second;
    }
};