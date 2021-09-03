/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
 * @date: 2021/9/2
 */
#include <iostream>

using namespace std;
 /**
  * Definition for singly-linked list.
  */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* p_k = NULL, *p_head = head;
    	while(p_head != NULL)
    	{
            if (k == 1)
            {
                p_k = head;
                k--;
            }
            else if (k == 0)
                p_k = p_k->next;
            else
                k--;
            p_head = p_head->next;
    	}
        return p_k;
    }
};