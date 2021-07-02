/**
 * @author: Bao Wenjie
 * @date: 2021/6/30
 * @link: https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <queue>
#include <ctype.h>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
	{
        string s = "[";
        queue<int> Q;
        char str[100];
        int last = 0;
        bool is_output = true;
        if (root == NULL)
            return "[]";
        Q.push((int)root);
        Q.push(-1);
    	while(Q.size() > 0)
    	{
            TreeNode* tmp = (TreeNode*)Q.front();
            int int_tmp = Q.front();
            Q.pop();
    		if(int_tmp == -1)
    		{
                Q.push(-1);
                if (!is_output)
                {
                	data[last] 
                    break;
                }
                else
                    is_output = false;
                continue;
    		}
    		if(tmp == NULL)
    		{
                s.append("null,");
                continue;
    		}
            is_output = true;
            _itoa_s(tmp->val, str, 10);
            s.append(str);
            s.append(",");
            Q.push((int)tmp->left);
            Q.push((int)tmp->right);
    	}
    	if(s[s.length() - 1] == ',')
    	{
            s[s.length() - 1] = ']';
    	}
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
	{
        queue<int> nums;
        queue<TreeNode*> q;
        int last = 1;
    	for(int i = 0; i < data.length(); i++)
    	{
    		if(data[i] == ',')
    		{
                data[i] = '\0';
                if (isdigit(data[i - 1]))
                    nums.push(atoi(data.substr(last, i - last).c_str()));
                else
                    nums.push(10000);
                last = i + 1;
    		}
    	}
    	if(data.length() > 2)
    	{
            data[data.length() - 1] = '\0';
            if (isdigit(data[data.length() - 2]))
                nums.push(atoi(data.substr(last, data.length() - last).c_str()));
            else
                nums.push(10000);
    	}
        if (nums.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode(nums.front());
        nums.pop();
        q.push(root);
    	while(!nums.empty())
    	{
            int tmp = nums.front();
            nums.pop();
            TreeNode* node_tmp = q.front();
            q.pop();
    		if(tmp == 10000)
    		{
                node_tmp->left = NULL;
    		}
            else
            {
                node_tmp->left = new TreeNode(tmp);
                q.push(node_tmp->left);
            }
            tmp = nums.front();
            nums.pop();
    		if(tmp == 10000)
    		{
                node_tmp->right = NULL;
    		}
            else
            {
                node_tmp->right = new TreeNode(tmp);
                q.push(node_tmp->right);
            }
    	}
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
	string s = "[1,2,3,null,null,4,5]";
    Codec codec;
    cout << codec.serialize(codec.deserialize(s));
}