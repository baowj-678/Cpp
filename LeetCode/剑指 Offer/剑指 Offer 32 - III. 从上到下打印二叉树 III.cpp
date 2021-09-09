/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
 * @date: 2021/9/9
 */
#include <iostream>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        bool isReverse = false;
        vector<vector<int>> ans;
        vector<int> tmp;
        if (root != NULL)
            Q.push(root);
        Q.push(NULL);
        while (Q.size() > 1)
        {
            TreeNode* node = Q.front();
            Q.pop();
            if (node == NULL)
            {
            	if(isReverse)
            	{
                    int left = 0, right = tmp.size() - 1;
                    while (left < right)
                        swap(tmp[left++], tmp[right--]);
            	}
                isReverse = !isReverse;
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
        if (isReverse)
        {
            int left = 0, right = tmp.size() - 1;
            while (left < right)
                swap(tmp[left++], tmp[right--]);
        }
        if (tmp.size() > 0)
            ans.push_back(tmp);
        return ans;
    }
};