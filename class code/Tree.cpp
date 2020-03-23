#include "Tree.h"
#include <stdio.h>
#include <malloc.h>


SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X, SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Element < X)
		return Find(X, T->Right);
	else if (T->Element > X)
		return Find(X, T->Left);
	else
		return T;
}

Position FindMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}

Position FindMax(SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Right == NULL)
		return T;
	else
		return FindMin(T->Right);
}

SearchTree Insert(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		T = (Position)malloc(sizeof(struct TreeNode));
		T->Element = X;
		T->Left = NULL;
		T->Right = NULL;
	}
	else
	{
		if (T->Element > X)
		{
			T->Left = Insert(X, T->Left);
		}
		else
		{
			T->Right = Insert(X, T->Right);
		}
	}
	return T;
}
