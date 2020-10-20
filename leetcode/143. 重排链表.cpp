/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <stdio.h>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow_p = head;
        ListNode* fast_p = head;
        while (fast_p)
        {
            fast_p = fast_p->next;
            if (fast_p)
            {
                slow_p = slow_p->next;
                fast_p = fast_p->next;
            }
        }
        if (slow_p)
        {
            fast_p = slow_p->next;
            slow_p->next = nullptr;
            slow_p = fast_p;
        }
        ListNode* head_ = nullptr;
        while (slow_p)
        {
            fast_p = slow_p->next;
            slow_p->next = head_;
            head_ = slow_p;
            slow_p = fast_p;
        }
        ListNode* head_new = head;
        head = head->next;
        fast_p = head_new;
        while (head && head_)
        {
            fast_p->next = head_;
            head_ = head_->next;
            fast_p = fast_p->next;
            fast_p->next = head;
            head = head->next;
            fast_p = fast_p->next;
        }
        if (head != nullptr)
        {
            fast_p->next = head;
            fast_p = fast_p->next;
            fast_p->next = nullptr;
        }
        else if (head_ != nullptr)
        {
            fast_p->next = head_;
            fast_p = fast_p->next;
            fast_p->next = nullptr;
        }
    }
};