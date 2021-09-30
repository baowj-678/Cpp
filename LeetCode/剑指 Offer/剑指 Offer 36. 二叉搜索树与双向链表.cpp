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
    Node* treeToDoublyList(Node* root) {

    }

	Node* subTree(Node* root, Node* fa, Node*& last)
    {
    	if(root->left)
    	{
            subTree(root->left, root, last);
        }

        root->left = last;
        last->right = root;
        last = root;
    	
    	if(root->right)
    	{
            subTree(root->right, root, last);
    	}
    }

};