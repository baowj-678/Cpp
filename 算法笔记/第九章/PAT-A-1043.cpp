/**
 * Author: Bao Wenjie
 * Date: 2021/3/9
 * Link: https://pintia.cn/problem-sets/994805342720868352/problems/994805440976633856
 */

#include <cstdio>
#define scanf scanf_s
#define printf printf_s

using namespace ::std;

const int maxn = 1010;

struct node
{
	int data;
	node* lchild;
	node* rchild;
};

node* insert(node* root, int data)
{
	if(root == NULL)
	{
		node* tmp = new node();
		tmp->data = data;
		tmp->rchild = tmp->lchild = NULL;
		return tmp;
	}
	if(root->data > data)
	{
		root->lchild = insert(root->lchild, data);
	}
	else
	{
		root->rchild = insert(root->rchild, data);
	}
	return root;
}

int path[maxn];
int seq[maxn];
int index = 0;
void preorder(node* root)
{
	if (root == NULL)
		return;
	path[index++] = root->data;
	preorder(root->lchild);
	preorder(root->rchild);
}

void preorder_m(node* root)
{
	if (root == NULL)
		return;
	path[index++] = root->data;
	preorder_m(root->rchild);
	preorder_m(root->lchild);
}

void postorder(node* root)
{
	if (root == NULL)
		return;
	postorder(root->lchild);
	postorder(root->rchild);
	path[index++] = root->data;
}

void postorder_m(node* root)
{
	if (root == NULL)
		return;
	postorder_m(root->rchild);
	postorder_m(root->lchild);
	path[index++] = root->data;
}

bool cmp(int* a, int* b, int n)
{
	for(int i = 0; i < n; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

int main()
{
	int N;
	scanf("%d", &N);
	node* root = NULL;
	for(int i = 0; i < N; i++)
	{
		int tmp = 0;
		scanf("%d", &tmp);
		seq[i] = tmp;
		root = insert(root, tmp);
	}
	index = 0;
	preorder(root);
	if(cmp(seq, path, N))
	{
		index = 0;
		postorder(root);
		printf("YES\n");
		for (int i = 0; i < N - 1; i++)
			printf("%d ", path[i]);
		printf("%d", path[N - 1]);
		return 0;
	}

	index = 0;
	preorder_m(root);
	if (cmp(seq, path, N))
	{
		index = 0;
		postorder_m(root);
		printf("YES\n");
		for (int i = 0; i < N - 1; i++)
			printf("%d ", path[i]);
		printf("%d", path[N - 1]);
		return 0;
	}
	printf("NO\n");
	return 0;
}
	
	
	