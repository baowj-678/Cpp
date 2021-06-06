/**
 * @author: Bao Wenjie
 * @date: 2021/6/6
 * @link: https://www.luogu.com.cn/problem/P1827
 */

#include <cstdio>
#include <cstring>
#define MAXN 30
#define scanf scanf_s

typedef struct node
{
	char c;
	node* left;
	node* right;
}node;

char pre_order[MAXN];
char in_order[MAXN];
char post_order[MAXN];
int index_ = 0;

void post_visit(node* root)
{
	if (root == nullptr)
		return;
	post_visit(root->left);
	post_visit(root->right);
	post_order[index_++] = root->c;
	return;
}

node* build_tree(int in_left, int in_right, int pre_left, int pre_right)
{
	node* tmp = new(node);
	if(in_left == in_right)
	{
		tmp->c = in_order[in_left];
		tmp->left = tmp->right = nullptr;
		return tmp;
	}
	int c = pre_order[pre_left];
	int i;
	for(i = in_left; i <= in_right; i++)
	{
		if(in_order[i] == c)
		{
			break;
		}
	}
	tmp->c = pre_order[pre_left];
	if (i == in_left)
		tmp->left = nullptr;
	else
		tmp->left = build_tree(in_left, i - 1, pre_left + 1, pre_left + 1 + (i - 1 - in_left));
	if (i == in_right)
		tmp->right = nullptr;
	else
		tmp->right = build_tree(i + 1, in_right, pre_left + 1 + (i - 1 - in_left) + 1, pre_right);
	return tmp;
}

int main()
{
	scanf("%s", in_order, 26);
	scanf("%s", pre_order, 26);
	int len = strlen(in_order);
	node* tmp = build_tree(0, len - 1, 0, len - 1);
	post_visit(tmp);
	post_order[len] = '\0';
	printf("%s", post_order);
	return 0;
}