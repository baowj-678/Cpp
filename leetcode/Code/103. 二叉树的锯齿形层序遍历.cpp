//给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
//
//例如：
//给定二叉树 [3, 9, 20, null, null, 15, 7],
//
//3
/// \
//9  20
/// \
//15   7
//返回锯齿形层序遍历如下：
//
//[
//    [3],
//    [20, 9],
//    [15, 7]
//]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace::std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode* > s;
        stack<TreeNode* > s_;
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        vector<int> tmp = { root->val };
        ans.push_back(tmp);
        s.push(root);
        bool direction = false;
        while (!s.empty() && !s_.empty())
        {
            tmp.clear();
            if (direction)
            {
                while (!s_.empty())
                {
                    TreeNode* node = s_.top();
                    s_.pop();
                    tmp.push_back(node->val);
                    if (node->left)
                        s.push(node->left);
                    if (node->right)
                        s.push(node->right);
                }
                direction = false;
            }
            else
            {
                while (!s.empty())
                {
                    TreeNode* node = s.top();
                    s.pop();
                    tmp.push_back(node->val);
                    if (node->right)
                        s_.push(node->right);
                    if (node->left)
                        s_.push(node->left);
                }
                direction = true;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};