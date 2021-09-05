/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
 * @date: 2021/9/5
 */
#include <iostream>
#include <map>

using namespace std;

 class Node {
 public:
     int val;
     Node* next;
     Node* random;

     Node(int _val) {
         val = _val;
         next = NULL;
         random = NULL;
     }
 };


class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> M;
        Node* head_ = NULL, *tmp = head, *tmp_;
        if (head != NULL)
        {
            head_ = new Node(head->val);
            tmp_ = head_;
            tmp = head->next;
            M[head] = head_;
        }
        else
            return NULL;
    	while(tmp != NULL)
    	{
            Node* cur = new Node(tmp->val);
            M[tmp] = cur;
            tmp_->next = cur;
            tmp_ = cur;
            tmp = tmp->next;
    	}
        tmp_->next = NULL;
        tmp_ = head_;
        tmp = head;
        M[NULL] = NULL;
    	while(tmp_ != NULL && tmp != NULL)
    	{
            tmp_->random = M[tmp->random];
            tmp_ = tmp_->next;
            tmp = tmp->next;
    	}
        return head_;
    }
};