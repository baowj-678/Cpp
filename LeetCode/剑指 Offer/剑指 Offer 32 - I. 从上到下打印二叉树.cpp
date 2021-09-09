/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
 * @date: 2021/9/9
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<int> ans;
        Q.push(root);
    	while(!Q.empty())
    	{
            TreeNode* tmp = Q.front();
            Q.pop();
    		if(tmp == NULL)
                continue;
            ans.push_back(tmp->val);
            Q.push(tmp->left);
            Q.push(tmp->right);
    	}
        return ans;
    }
};