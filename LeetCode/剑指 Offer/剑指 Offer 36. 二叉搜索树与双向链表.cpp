/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
 * @date: 2021/9/21
 */
#include <iostream>

 class Node {
 public:
     int val;
     Node* left;
     Node* right;

     Node() {}

     Node(int _val) {
         val = _val;
         left = NULL;
         right = NULL;
     }

     Node(int _val, Node* _left, Node* _right) {
         val = _val;
         left = _left;
         right = _right;
     }
 };

class Solution {
public:
    Node* head = NULL;
    Node* last = NULL;
    Node* tail = NULL;
	
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return NULL;
        tail = subTree(root);
        head->left = tail;
        tail->right = head;
        return head;
    }

	Node* subTree(Node* root)
    {
        if (root->left)
            subTree(root->left);
    	
    	if(!head)
    	{
            head = root;
            last = root;
    	}
        else
        {
            last->right = root;
            root->left = last;
            last = root;
        }
    	
        if (root->right)
            return subTree(root->right);
        else
            return root;
    }

};