#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include "Stack.h"
#include "Tree.h"

void infix(SearchTree root);
SearchTree New_Tree(char c, SearchTree left, SearchTree right)
{
	SearchTree Tmp = (SearchTree)malloc(sizeof(struct TreeNode));
	if (Tmp != NULL)
	{
		Tmp->Element = c;
		Tmp->Left = left;
		Tmp->Right = right;
	}
	return Tmp;
}

SearchTree GenerateATree(char s[])
{
	Stack stack = CreateStack();
	MakeEmpty(stack);

	int i = 0;
	while (s[i] != 0)
	{
		if (isalpha(s[i]))
		{
			SearchTree Tmp = New_Tree(s[i], NULL, NULL);
			Push(Tmp, stack);
		}
		else
		{
			SearchTree right = Top(stack);
			Pop(stack);
			SearchTree left = Top(stack);
			Pop(stack);
			SearchTree Atree = New_Tree(s[i], left, right);
			Push(Atree, stack);
		}
		i++;
	}

	SearchTree t = Top(stack);
	DisposeStack(stack);
	return t;
}

void postfix(SearchTree root) 
{ 
	if (root != NULL) 
	{ 
		postfix(root->Left); 
		postfix(root->Right); 
		printf("%c", root->Element);
	} 
}

void infix(SearchTree root)
{
	if (root != NULL)
	{
		infix(root->Left);
		printf("%c", root->Element);
		infix(root->Right);
	}
}

void prefix(SearchTree root)
{
	if (root != NULL)
	{
		printf("%c", root->Element);
		prefix(root->Left);
		prefix(root->Right);
	}
}

int main()
{
	char s[] = "ab+cde+**";
	SearchTree t = GenerateATree(s);
	postfix(t);
	printf("\n");
	infix(t);
	printf("\n");
	prefix(t);

}