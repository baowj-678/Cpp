#include "Stack.h"
#include <malloc.h>

struct Node {
	ElementType Element;
	PtrToNode Next;
};

int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

Stack CreateStack(void)
{
	Stack S = (Stack)malloc(sizeof(struct Node));
	if (S != NULL)
		S->Next = NULL;
	return S;
}
void DisposeStack(Stack S);

void MakeEmpty(Stack S)
{
	S = S->Next;
	PtrToNode temp;
	while (S)
	{
		temp = S->Next;
		free(S);
		S = temp;
	}
}
void Push(ElementType X, Stack S)
{
	PtrToNode temp = (PtrToNode)malloc(sizeof(struct Node));
	if (temp != NULL)
	{
		temp->Element = X;
		temp->Next = S->Next;
		S->Next = temp;
	}
}

ElementType Top(Stack S)
{
	if (!IsEmpty(S))
	{
		return S->Next->Element;
	}
	return 0;
}
void Pop(Stack S)
{
	if (!IsEmpty(S))
	{
		PtrToNode temp = S->Next;
		S->Next = temp->Next;
		free(temp);
	}
}

void DisposeStack(Stack S)
{
	PtrToNode temp = S;
	while (S!=NULL)
	{
		temp = S->Next;
		free(S);
		S = temp;
	}
}