/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
 * @date: 2021/9/21
 */
#include <iostream>
#include <vector>

using namespace std;

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
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        if (root == NULL)
            return ans;
        findPath(ans, path, root, target);
    	return ans;
    }

	void findPath(vector<vector<int>>& ans, vector<int>& path, TreeNode* root, int target)
    {
        path.push_back(root->val);
        target -= root->val;
	    if(root->left == NULL && root->right == NULL)
	    {
            if (target == 0)
            {
                ans.push_back(path);
            }
            path.pop_back();
            return;
	    }
    	if (root->left)
			findPath(ans, path, root->left, target);
        if (root->right)
            findPath(ans, path, root->right, target);
        path.pop_back();
    }
};