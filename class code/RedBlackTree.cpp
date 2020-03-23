#include "RedBlackTree.h"
#include <malloc.h>

struct RedBlackNode
{
	ElementType Element;
	PtrToRedBlackNode Left;
	PtrToRedBlackNode Right;
	ColorType Color;
};

RedBlackTree Initialize(void)
{
	RedBlackTree T = (RedBlackTree)malloc(sizeof(struct RedBlackNode));
	if (T == NULL)
		return NULL;
	T->Left = NULL;
	T->Right = NULL;
	T->Color = Black;
	T->Element = 0;
	return T;
}

Position SingleRotateWithLeft(Position P)
{
	Position L = P->Right;
	if (L == NULL)
		return NULL;
	P->Right = L->Left;
	L->Left = P;
	return L;
}

Position SingleRotateWithRight(Position P)
{
	Position R = P->Left;
	if (R == NULL)
		return NULL;
	P->Left = R->Right;
	R->Right = P;
	return R;
}

RedBlackTree Insert(ElementType Item, RedBlackTree T)
{
	Position X, P, GP, GGP;
	X = P = GP = T;
	Position NewNode = (Position)malloc(sizeof(struct RedBlackNode));

	while (X->Element != Item)
	{
		GGP = GP;
		GP = P;
		P = X;
		if (Item < X->Element)
			X = X->Left;
		else
			X = X->Right;
		if (X->Left->Color == Red && X->Right->Color == Red)
			;
	}

	if (X != NULL)
		return NewNode;
	X = (Position)malloc(sizeof(struct RedBlackNode));
	if (X == NULL)
		return NULL;
	X->Element = Item;
	X->Left = X->Right = NULL;

	if (Item < P->Element)
		P->Left = X;
	else
		P->Right = X;
	}
}

void HandleReorient(ElementType Item, RedBlackTree T)
{
	X->
}