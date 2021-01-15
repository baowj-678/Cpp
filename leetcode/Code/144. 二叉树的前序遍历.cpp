//给定一个二叉树，返回它的 前序 遍历。
//
//示例 :
//
//输入: [1, null, 2, 3]
//1
//\
//2
///
//3
//
//输出: [1, 2, 3]
//进阶 : 递归算法很简单，你可以通过迭代算法完成吗？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/binary-tree-preorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* tmp = s.top();
            s.pop();
            if (tmp == NULL)
                continue;
            ans.push_back(tmp->val);
            s.push(tmp->right);
            s.push(tmp->left);
        }
    }
};