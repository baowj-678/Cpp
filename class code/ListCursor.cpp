#include "ListCursor.h"
#include <malloc.h>
#include <stdio.h>
#define SpaceSize	100
#define ROOT		0
struct Node 
{
	ElementType Element;
	Position Next;
};

struct Node CursorSpace[SpaceSize];
void InitializeCursorSpace(void)
{
	int i = 0;
	for (; i < SpaceSize - 1; i++)
	{
		CursorSpace[i].Next = i + 1;
	}
	CursorSpace[i].Next = 0;
}

bool IsEmpty(const List L)
{
	if (CursorSpace[L].Next == 0)
		return true;
	else
		return false;
}

List CreateList(void)
{
	if (CursorSpace[ROOT].Next == 0)
	{
		return 0;
	}
	else
	{
		List NewList = CursorSpace[ROOT].Next;
		CursorSpace[ROOT].Next = CursorSpace[NewList].Next;
		CursorSpace[NewList].Next = 0;
		CursorSpace[NewList].Element = 0;
		return NewList;
	}
}

bool Append(ElementType element, List L)
{
	if (CursorSpace[ROOT].Next == 0)
		return false;
	else
	{
		List NewNode = CursorSpace[ROOT].Next;
		CursorSpace[ROOT].Next = CursorSpace[NewNode].Next;
		CursorSpace[NewNode].Next = CursorSpace[L].Next;
		CursorSpace[L].Next = NewNode;
		CursorSpace[NewNode].Element = element;
		return true;
	}
}

ElementType First(List L)
{
	if (CursorSpace[L].Next == 0)
		return -1;
	else
	{
		Position NextElement = CursorSpace[L].Next;
		return CursorSpace[NextElement].Element;
	}
}

Position Find(ElementType element, List L)
{
	if (CursorSpace[L].Next == 0)
		return 0;
	else
	{
		Position temp = CursorSpace[L].Next;
		while (CursorSpace[temp].Next != 0)
		{
			temp = CursorSpace[temp].Next;
		}
		return temp;
	}
}

void Delete(ElementType element, List L)
{
	if (CursorSpace[L].Next == 0)
		return;
	else
	{
		Position Last = L;
		Position head = CursorSpace[L].Next;
		while (CursorSpace[head].Element != element && CursorSpace[head].Next != 0)
		{
			Last = head;
			head = CursorSpace[head].Next;
		}
		if (CursorSpace[head].Element == element)
		{
			CursorSpace[Last].Next = CursorSpace[head].Next;
			CursorSpace[head].Next = CursorSpace[ROOT].Next;
			CursorSpace[ROOT].Next = head;
		}
		else
			return;
	}
}

void Insert(ElementType element, List L, Position P)
{
	if (P == L)
	{
		Append(element, L);
	}
	else
	{
		if (CursorSpace[ROOT].Next != 0)
		{
			Position NewElement = CursorSpace[ROOT].Next;
			CursorSpace[ROOT].Next = CursorSpace[NewElement].Next;
			CursorSpace[NewElement].Element = element;
			CursorSpace[NewElement].Next = CursorSpace[P].Next;
			CursorSpace[P].Next = NewElement;
		}
	}
}

bool IsSpaceEmpty(void)
{
	if (CursorSpace[ROOT].Next == 0)
		return true;
	else
		return false;
}

void DeleteList(List L)
{
	while (CursorSpace[L].Next != 0)
	{
		Position temp = CursorSpace[L].Next;
		CursorSpace[L].Next = CursorSpace[temp].Next;
		CursorSpace[temp].Next = CursorSpace[ROOT].Next;
		CursorSpace[ROOT].Next = temp;
	}
	CursorSpace[L].Next = CursorSpace[ROOT].Next;
	CursorSpace[ROOT].Next = L;
}

void PrintList(List L)
{
	if (CursorSpace[L].Next == 0)
	{
		printf("Empty\n");
		return;
	}
	else
	{
		Position head = CursorSpace[L].Next;
		while (CursorSpace[head].Next != 0)
		{
			printf("[%d, %d]\n",head, CursorSpace[head].Element);
			head = CursorSpace[head].Next;
		}
		printf("[%d, %d]\n",head, CursorSpace[head].Element);
	}
}

int main()
{
	int NowNum = 0;
	int index;
	int x;
	Position p;
	List L[10];
	int c;
	printf("Please input:\n1.intial the sp\
\ace\n2.create a new List\n3.append element to l\
\ist L\n4.Print the List\n5.Delete List\n6.\
\Check List is Empty\n7.Insert element\n");
	scanf_s("%d", &c);
	while (c != 0)
	{
		switch (c)
		{
		case 1:
			InitializeCursorSpace();
			NowNum = 0;
			printf("ok\n\n");
			break;

		case 2:
			L[NowNum] = CreateList();
			printf("you have create No.[%d] List\n\n", NowNum);
			NowNum++;
			break;

		case 3:
			printf("Please input the index of List:\n");
			scanf_s("%d", &index);
			printf("Please input the element:\n");
			
			scanf_s("%d", &x);
			if (index < NowNum)
			{
				if (Append(x, L[index]))
				{
					printf("[%d] Insert List[%d] ok\n\n", x, index);
				}
				else
				{
					printf("There is no space\n\n");
				}
			}
			else
			{
				printf("the list don't exist\n\n");
			}
			break;

		case 4:
			printf("Please input the index of List\n");
			scanf_s("%d", &index);
			if (index < NowNum)
			{
				PrintList(L[index]);
				printf("\n");
			}
			else
			{
				printf("List [%d] don't exist\n\n", index);
			}
			break;

		case 5:
			printf("Please input the index of List you want to del\n");
			scanf_s("%d", &index);
			if (index < NowNum)
			{
				DeleteList(L[index]);
				printf("List [%d] delete successfully\n\n", index);
			}
			else
			{
				printf("List [%d] don't exist\n\n", index);
			}
			break;

		case 6:
			printf("Please input the index of List\n");
			scanf_s("%d", &index);
			if (index < NowNum)
			{
				if(IsEmpty(L[index]))
					printf("List [%d] is Empty\n\n", index);
				else
					printf("List [%d] isn't Empty\n\n", index);
			}
			else
			{
				printf("List [%d] don't exist\n\n", index);
			}
			break;

		case 7:
			printf("Please input the index of the List\n");
			scanf_s("%d", &index);
			printf("Please input the element\n");
			scanf_s("%d", &x);
			printf("Please input the position you want to insert after\n");
			scanf_s("%d", &p);
			Insert(x, L[index], p);
			printf("[%d] Insert successfully\n\n", x);

		default:
			break;
		}
		printf("Please input:\n1.intial the sp\
\ace\n2.create a new List\n3.append element to l\
\ist L\n4.Print the List\n5.Delete List\n6.\
\Check List is Empty\n7.Insert element\n"); 
		scanf_s("%d", &c);
	}
}
