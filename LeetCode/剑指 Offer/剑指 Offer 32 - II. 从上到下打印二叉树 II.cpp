/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
 * @date: 2021/9/9
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<vector<int>> ans;
        vector<int> tmp;
        if (root != NULL)
            Q.push(root);
        Q.push(NULL);
    	while(Q.size() > 1)
    	{
            TreeNode* node = Q.front();
            Q.pop();
    		if(node == NULL)
    		{
                ans.push_back(tmp);
                tmp.clear();
                Q.push(NULL);
    			continue;
    		}
            tmp.push_back(node->val);
            if (node->left != NULL)
                Q.push(node->left);
            if (node->right != NULL)
                Q.push(node->right);
    	}
        if (tmp.size() > 0)
            ans.push_back(tmp);
        return ans;
    }
};