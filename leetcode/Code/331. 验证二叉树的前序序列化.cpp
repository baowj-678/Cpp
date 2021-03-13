/**
 * @file 331. 验证二叉树的前序序列化.cpp
 * @author Bao Wenjie
 * @brief https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/
 * @version 0.1
 * @date 2021-03-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <queue>

using namespace::std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<int> tmp;
        for(int i = 0; i < preorder.length(); i++)
        {
            if(preorder[i] == ',')
                continue;
            else if(preorder[i] == '#')
            {
                tmp.push_back(-1);
            }
            else if(isdigit(preorder[i]))
            {
                int num = preorder[i] - '0';
                int j = i;
                while(++j < preorder.length() && isdigit(preorder[j]))
                {
                    num = 10 * num + preorder[j] - '0';
                }
                tmp.push_back(num);
                i = j - 1;
            }
        }
        queue<int> Q;
        int i = 0;
        Q.push(tmp[i++]);
        while(!Q.empty())
        {
            if(Q.front() != -1)
            {
                Q.pop();
                if(i >= tmp.size())
                    return false;
                Q.push(tmp[i++]);
                if(i >= tmp.size())
                    return false;
                Q.push(tmp[i++]);
            }
            else
            {
                Q.pop();
            }
        }
        if(i < tmp.size())
            return false;
        return true;
    }
};