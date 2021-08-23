/**
 * Author: Bao Wenjie
 * Date: 2021/3/28
 * Link: https://leetcode-cn.com/problems/binary-search-tree-iterator/
 */

//Definition for a binary tree node.
#include <iostream>
#include <vector>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
	vector<TreeNode*> vec;
	int p = -1;
    BSTIterator(TreeNode* root) {
    	makeVec(root);
    	this->p = -1;
    }
    
    void makeVec(TreeNode* root)
    {
    	if(root == NULL)
    		return;
    	makeVec(root->left);
    	this->vec.push_back(root);
    	makeVec(root->right);
	}
    
    int next() {
    	return (this->vec[++this->p])->val;
    }
    
    bool hasNext() {
    	if(this->p < (int)this->vec.size() - 1)
    		return true;
    	return false;
    }
};
