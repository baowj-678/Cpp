#include "ListNode.h"

#ifndef _LIST_
#define _LIST_



List MakeEmpty(List L)
{
	Position p = L->Next;
	while (p)
	{
		Position temp = p;
		p = p->Next;
		free(temp);
	}
	L->Next = p;
	return L;
}

bool IsEmpty(List L)
{
	if (L->Next)
		return true;
	else
		return false;
}

bool IsLast(Position P, List L)
{
	return P->Next == NULL;
}

void Delete(ElementType X, List L)
{
	Position temp;
	temp = L->Next;
	while (IsLast(temp, L))
	{
		if (temp->Next->Element == X)
		{
			L = temp->Next;
			temp->Next = temp->Next->Next;
			free(L);
			break;
		}
	}
}

Position First(List L)
{
	return L->Next;
}

void DeleteList(List L)
{
	PtrToNode temp = L;
	while (L)
	{
		temp = L;
		L->Next;
		free(temp);
	}
}

Position Find(ElementType X, List L)
{
	L = L->Next;
	while (L)
	{
		if (L->Element == X)
			break;
		L = L->Next;
	}
	return L;
}


PtrToNode createNode(ElementType Element)
{
	PtrToNode point = (PtrToNode)malloc(sizeof(struct Node));
	point->Element = Element;
	point->Next = NULL;
	return point;
}

void del(ListNode* head)
{
	while (head)
	{
		PNode temp = head;
		head = head->next;
		free(temp);
	}
}

void print(ListNode* head)
{
	while (head)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

#endif // !_LIST_
