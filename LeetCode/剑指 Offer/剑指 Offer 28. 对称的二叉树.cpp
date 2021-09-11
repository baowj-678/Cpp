/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
 * @date: 2021/9/11
 */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        if (isFullSym(root->left, root->right) &&
            isSymmetric(root->left) &&
            isSymmetric(root->right))
            return true;
        return false;
    }

	bool isFullSym(TreeNode* left, TreeNode* right)
    {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL)
            return false;
        if (left->val == right->val &&
            isFullSym(left->left, right->left) &&
            isFullSym(left->right, right->right))
            return true;
        return false;
    }
};