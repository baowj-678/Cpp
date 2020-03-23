#include "SplayNode.h"
#include <malloc.h>

struct SplayNode
{
	ElementType Element;
	SplayTree Left;
	SplayTree Right;
};

SplayTree Initialize(void)
{
	SplayTree T = (SplayTree)malloc(sizeof(struct SplayNode));
	if (T != NULL)
	{
		T->Element = 0;
		T->Left = NULL;
		T->Right = NULL;
		return T;
	}
	return T;
}

SplayTree DeleteTree(SplayTree T)
{
	if (T == NULL)
		return NULL;
	MakeEmpty(T->Left);
	MakeEmpty(T->Right);
	free(T);
	return NULL;
}

SplayTree MakeEmpty(SplayTree T)
{
	DeleteTree(T->Left);
	DeleteTree(T->Right);
	return T;
}

SplayTree Splay(ElementType Item, Position X)
{
	static struct SplayNode Header;
	//
	Position LeftTreeMax, RightTreeMin;
	Header.Left = Header.Right = NULL;
	LeftTreeMax = RightTreeMin = &Header;

	while (Item != X->Element)
	{
		if (Item < X->Element)
		{
			if (Item < X->Left->Element)
				X = SingleRotateWithLeft(X);
			if (X->Left == NULL)
				break;
			RightTreeMin->Left = X;
			RightTreeMin = X;
			X = X->Left;
		}
		else
		{
			if (Item > X->Right->Element)
				X = SingleRotateWithRight(X);
			if (X->Right == NULL)
				break;
			LeftTreeMax->Right = X;
			LeftTreeMax = X;
			X = X->Right;
		}
	}
	LeftTreeMax->Right = X->Left;
	RightTreeMin->Left = X->Right;
	X->Left = Header.Right;
	X->Right = Header.Left;

	return X;

}
SplayTree SingleRotateWithLeft(Position X)
{
	Position L = X->Left;
	Position LL = L->Left;
	X->Left = L->Right;
	L->Right = X;
	L->Left = NULL;
	LL->Right = L;
	return LL;
}

SplayTree SingleRotateWithRight(Position X)
{
	Position R = X->Right;
	Position RR = R->Right;
	X->Right = R->Left;
	R->Left = X;
	R->Right = NULL;
	RR->Left = R;
	return RR;
}

SplayTree Insert(ElementType X, SplayTree T)
{
	Position NewNode = (Position)malloc(sizeof(struct SplayNode));
	if (NewNode == NULL)
	{
		return NULL;
	}
	NewNode->Element = X;
	if (T == NULL)
	{
		NewNode->Left = NewNode->Right = NULL;
		T = NewNode;
	}
	else
	{
		T = Splay(X, T);
		if (X < T->Element)
		{
			//NewNode becomes the root
			NewNode->Left = T->Left;
			NewNode->Right = T;
			T->Left = NULL;
			T = NewNode;
		}
		else if (X > T->Element)
		{
			NewNode->Right = T->Right;
			NewNode->Left = T;
			T->Right = NULL;
			T = NewNode;
		}
		else
			//Alrady Exist X
			return T;
	}
	return T;
}
SplayTree Remove(ElementType X, SplayTree T)
{
	Position NewTree;
	if (T == NULL)
		return T;
	else
	{
		NewTree = Splay(X, T);
		if (NewTree->Element != X)
			return NewTree;
		if (NewTree->Left == NULL)
			return NewTree->Right;
		else
		{
			NewTree = NewTree->Left;
			//NewNode's Right Child is Empty
			NewTree = Splay(X, NewTree);
			NewTree->Right = T->Right;
		}
		free(T);
		T = NewTree;
	}
	return T;
}
SplayTree FindMin(SplayTree T)
{
	if (T == NULL)
		return NULL;
	while (T->Left!=NULL)
	{
		T = T->Left;
	}
	return T;
}
SplayTree FindMax(SplayTree T)
{
	if (T == NULL)
		return NULL;
	while (T->Right != NULL)
	{
		T = T->Right;
	}
	return T;
}

SplayTree Find(ElementType X, SplayTree T)
{
	T = Splay(X, T);
	if (T->Element == X)
		return T;
	else
		return NULL;
}

ElementType Retrieve(SplayTree T)
{
	if (T == NULL)
		return -1;
	else
		return T->Element;

}