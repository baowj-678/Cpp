/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
 * @date: 2021/9/19
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* tmpA = headA, * tmpB = headB;
        bool aSecond = false, bSecond = false;
        if (!headA || !headB)
            return NULL;
    	while(true)
    	{
    		if(tmpA == NULL)
    		{
                if (aSecond == false)
                {
                    aSecond = true;
                    tmpA = headB;
                }
                else
                    break;
    		}
    		if(tmpB == NULL)
    		{
                if (bSecond == false)
                {
                    bSecond = true;
                    tmpB = headA;
                }
    			else
                    break;
    		}
            if (tmpA == tmpB)
                return tmpA;
            tmpA = tmpA->next;
            tmpB = tmpB->next;
    	}
        return NULL;
    }
};