/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
 * @date: 2021/9/21
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int ans;
        subF(root, k, ans);
        return ans;
    }

	bool subF(TreeNode* root, int& k, int& ans)
    {
        if (root->right)
        {
            if (subF(root->right, k, ans))
                return true;
        }
    	
        k--;
        if (k == 0)
        {
            ans = root->val;
            return true;
        }
    	
    	if(root->left)
    	{
            return subF(root->left, k, ans);
    	}
        return false;
    }
};