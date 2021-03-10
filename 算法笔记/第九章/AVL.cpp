/**
 * @file AVL.cpp
 * @author Bao Wenjie
 * @brief 平衡二叉树
 * @version 0.1
 * @date 2021-03-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

using namespace::std;
struct node
{
    int v, height;
    node* lchild, *rchild;
};

/**
 * @brief 创建新节点
 * 
 * @param v 
 * @return node* 
 */
node* newNode(int v)
{
    node* Node = new node;
    Node->v = v;
    Node->height =  1;
    Node->lchild = Node->rchild = NULL;
    return Node;
}


/**
 * @brief get the height of sub-tree follows rooot
 * 
 * @param root 
 * @return int 
 */
int getHeight(node* root)
{
    if(root == NULL)
        return 0;
    return root->height;
}


/**
 * @brief Get the Balance Factor of sub-tree of root
 * 
 * @param root 
 * @return int 
 */
int getBalanceFactor(node* root)
{
    return getHeight(root->lchild) - getHeight(root->rchild);
}


/**
 * @brief Update the Height of node root
 * 
 * @param root 
 */
void updateHeight(node* root)
{
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}


/**
 * @brief Get the point of node whose value if x
 * 
 * @param root 
 * @param x 
 */
node* search(node* root, int x)
{
    if(root == NULL)
    {
        printf("search failed!\n");
        return NULL;
    }

    if(x == root->v)
    {
        printf("%d\n", root->v);
        return root;
    }
    else if(x < root->v)
    {
        return search(root->lchild, x);
    }
    else
    {
        return search(root->rchild, x);
    }
}


/**
 * @brief Left Rotation
 * 
 * @param root 
 */
void LR(node* &root)
{
    node* tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

/**
 * @brief Right Rotation
 * 
 * @param root 
 */
void RR(node* &root)
{
    node* tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

/**
 * @brief Insert Node
 * 
 * @param root 
 * @param v 
 */
void insert(node* & root, int v)
{
    if(root == NULL)
    {
        root = newNode(v);
        return;
    }
    if(v < root->v)
    {
        insert(root->lchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2)
        {
            if(getBalanceFactor(root->lchild) == 1) // LL
            {
                RR(root);
            }
            else if(getBalanceFactor(root->lchild) == -1) // LR
            {
                LR(root->lchild);
                RR(root);
            }
        }
    }
    else
    {
        insert(root->rchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2)
        {
            if(getBalanceFactor(root->rchild) == 1) // RL
            {
                RR(root->rchild);
                LR(root);
            }
            else if(getBalanceFactor(root->rchild) == -1) // RR
            {
                LR(root);
            }
        }
    }
}

/**
 * @brief Create AVL Tree from Array
 * 
 * @param data 
 * @param n 
 * @return node* 
 */
node* Create(int data[], int n)
{
    node* root = NULL;
    for(int i = 0; i < n; i++)
    {
        insert(root, data[i]);
    }
    return root;
}



int main()
{
    int a[] = {1, 2, 3, 4, 5};
    node* root = Create(a, 5);
    printf("jhefc");
}