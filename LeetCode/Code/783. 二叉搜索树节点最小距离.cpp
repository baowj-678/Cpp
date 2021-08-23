#include <iostream>
#include <cmath>

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
    int min_gap = 999999;
    int minDiffInBST(TreeNode* root) {
        DFS(root);
        return min_gap;
    }

    pair<int, int> DFS(TreeNode* root)
    {
        pair<int, int> ans = {999999, -999999};
        if(root == NULL)
            return ans;
        pair<int, int> left = DFS(root->left);
        pair<int, int> right = DFS(root->right);
        min_gap = min(min(abs(root->val - left.second), abs(root->val - right.first)), min_gap);
        ans.first = min(min(ans.first, root->val), left.first);
        ans.second = max(max(ans.second, root->val), right.second);
        return ans;
    }
};


int main()
{

    return 0;
}
