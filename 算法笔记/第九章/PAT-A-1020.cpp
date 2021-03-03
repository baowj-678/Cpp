/**
 * Author: Bao Wenjie
 * Date: 2021/3/3
 * Link: https://pintia.cn/problem-sets/994805342720868352/problems/994805485033603072
 */

#include <cstdio>
#include <queue>
#define scanf scanf_s
#define printf printf_s

using namespace ::std;

struct Node
{
	int value;
	Node* lchild;
	Node* rchild;
};
const int maxn = 40;
int postorder[maxn];
int inorder[maxn];

Node* build_tree(int postL, int postR, int inL, int inR)
{
	if (postL > postR)
		return NULL;
	Node* node = new Node;
	node->value = postorder[postR];
	node->lchild = node->rchild = NULL;
	int k = 0;
	for(k = inL; k <= inR; k++)
	{
		if(inorder[k] == postorder[postR])
			break;
	}
	int numLeft = k - inL;
	node->lchild = build_tree(postL, postL + numLeft - 1, inL, k - 1);
	node->rchild = build_tree(postL + numLeft, postR - 1, k + 1, inR);
	return node;
}

void BFS(Node* root, int n)
{
	int i = 0;
	queue<Node*> Q;
	Q.push(root);
	while(!Q.empty())
	{
		Node* node = Q.front();
		Q.pop();
		printf("%d", node->value);
		i++;
		if (i < n)
			printf(" ");
		if (node->lchild != NULL)
			Q.push(node->lchild);
		if (node->rchild != NULL)
			Q.push(node->rchild);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", postorder + i);
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d", inorder + i);
	}
	Node* root = build_tree(0, n - 1, 0, n - 1);
	BFS(root, n);
	return 0;
}