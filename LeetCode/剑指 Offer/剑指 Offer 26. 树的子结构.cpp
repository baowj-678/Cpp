/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
 * @date: 2021/9/11
 */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
    	if (B == NULL || A == NULL)
            return false;
        if (isFullSub(A, B))
            return true;
        if (isSubStructure(A->left, B) || isSubStructure(A->right, B))
            return true;
        return false;
    }

	bool isFullSub(TreeNode* A, TreeNode* B)
    {
        if (B == NULL)
            return true;
        if (A == NULL)
            return false;
        if (A->val == B->val &&
            isFullSub(A->left, B->left) &&
            isFullSub(A->right, B->right))
            return true;
        return false;
    }
};