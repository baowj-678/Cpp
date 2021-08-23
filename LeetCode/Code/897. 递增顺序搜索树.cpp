/**
 * Author: Bao Wenjie
 * Date: 2021/4/25
 * Link: https://leetcode-cn.com/problems/increasing-order-search-tree/
 */

#include <iostream>
#include <vector>
using namespace::std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode* tail = NULL;
	
    TreeNode* increasingBST(TreeNode* root)
	{
		return recursiveBST(root);
    }

	TreeNode* recursiveBST(TreeNode* root)
    {
		TreeNode* head_tmp = root;
		tail = NULL;
    	if(root->left)
			head_tmp = recursiveBST(root->left);
		if (tail)
		{
			tail->right = root;
			root->left = NULL;
		}
		if (root->right)
		{
			TreeNode* tmp = recursiveBST(root->right);
			root->right = tmp;
		}
		else
		{
			tail = root;
		}
		return head_tmp;
    }
};