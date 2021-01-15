//请判断一个链表是否为回文链表。
//
//示例 1:
//
//输入: 1->2
//输出 : false
//示例 2 :
//
//	输入 : 1->2->2->1
//	输出 : true
//	进阶：
//	你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/palindrome-linked-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//Definition for singly-linked list.

#include <iostream>

using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow_p = head, * fast_p = head, * tmp= head;
        bool is_half = false;
        head = NULL;
        while (fast_p)
        {
            fast_p = fast_p->next;
            if (!fast_p)
            {
                is_half = true;
                break;
            }
            fast_p = fast_p->next;
            tmp = slow_p->next;
            slow_p->next = head;
            head = slow_p;
            slow_p = tmp;
        }
        if (is_half && slow_p)
        {
            slow_p = slow_p->next;
        }
        while (slow_p && head)
        {
            if (slow_p->val == head->val)
            {
                slow_p = slow_p->next;
                head = head->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

