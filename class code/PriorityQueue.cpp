#include "PriorityQueue.h"
#include <stdio.h>
#include <malloc.h>

struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType* Element;
};

PriorityQueue Initialize(int MaxElement)
{
	PriorityQueue Heap;
	Heap = (PriorityQueue)malloc(sizeof(struct HeapStruct));
	if (Heap == nullptr)
	{
		printf("There is no space\n");
		return Heap;
	}
	
	Heap->Element = (ElementType*)malloc(sizeof(ElementType) * (MaxElement + 1));
	Heap->Capacity = MaxElement;
	Heap->Size = 0;
	Heap->Element[0] = 0;
	return Heap;
}

void Destroy(PriorityQueue H)
{
	if (H == nullptr)
		return;
	if (H->Element != nullptr)
		free(H->Element);
	free(H);
}

void MakeEmpty(PriorityQueue H)
{
	H->Size = 0;//
}

bool IsEmpty(PriorityQueue H)
{
	return H->Size == 0;
}

int IsFull(PriorityQueue H)
{
	return H->Capacity <= H->Size;
}

void Insert(ElementType X, PriorityQueue H)
{
	int i;
	if (IsFull(H))
	{
		printf("It's full\n");
		return;
	}
	for (i = ++(H->Size); H->Element[i / 2] > X; i /= 2)
		H->Element[i] = H->Element[i / 2];
	H->Element[i] = X;
}

ElementType FindMin(PriorityQueue H)
{
	if (IsEmpty(H))
	{
		printf("It's Empty\n");
		return -1;
	}
	return H->Element[1];
}

ElementType DeleteMin(PriorityQueue H)
{
	int i, Child;
	ElementType MinElement, LastElement;
	if (IsEmpty(H))
	{
		printf("It's Empty\n");
		return -1;
	}
	//store the first element
	MinElement = H->Element[1];
	//store the last element
	LastElement = H->Element[H->Size--];

	for (i = 1; i * 2 <= H->Size; i = Child)
	{
		Child = i * 2;
		if (Child != H->Size && H->Element[Child + 1] < H->Element[Child])
			Child++;

		if (LastElement > H->Element[Child])
			H->Element[i] = H->Element[Child];
		else
			break;
		//if certain Element only have one Child then,it must be the last element
	}
	H->Element[i] = LastElement;
	return MinElement;
}

PriorityQueue BuildHeap(int* s, int n)
{
	PriorityQueue H = Initialize(n);
	for (int i = 0; i < n; i++)
	{
		H->Element[i + 1] = s[i];
		H->Size++;
	}
	for (int i = H->Size / 2; i > 0; i--)
	{
		PercolateDown(H, i);
	}
	return H;
}

void PercolateDown(PriorityQueue H, Position p)
{
	Position Child;
	ElementType Element = H->Element[p];
	while (p <= H->Size)
	{
		int Child = p * 2;
		if (Child >= H->Size)
			break;
		if (H->Element[Child] > H->Element[Child + 1])
			Child++;
		if (H->Element[p] > H->Element[Child])
			H->Element[p] = H->Element[Child];
		else
			break;
		p = Child;
	}
	if (p * 2 == H->Size && H->Element[p] > H->Element[p * 2])
	{
		H->Element[p] = H->Element[H->Size];
		p *= 2;
	}
	H->Element[p] = Element;
}
void PrintHeap(PriorityQueue H)
{
	for (int i = 0; i <= H->Size; i++)
	{
		printf("%d ", H->Element[i]);
	}
	printf("\n");
	for (int i = 0; i <= H->Size; i++)
	{
		printf("%d ", i);
	}
	printf("\n\n");
}

void Print(int* s, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
}

PriorityQueue HeapSort(int* s, int n)
{
	PriorityQueue H = BuildHeap(s, n);
	PrintHeap(H);
	for (int i = 0; i < n; i++)
	{
		H->Element[n - i] = DeleteMin(H);
	}
	return H;
}
int main()
{
	int flag;
	printf("0.quit\n1.Initiate a Heap;\n2.Mkae the Heap Empty;\n3.Insert an ele\
ment\n4.Delete the min\n5.Print the heap\n");
	PriorityQueue H = NULL;
	ElementType Element;
	int length = 0;
	scanf_s("%d", &flag);
	while (flag != 0)
	{
		switch (flag)
		{
		case 0:
			Destroy(H);
			break;
		case 1:
			printf("Please input the length of heap\n");
			scanf_s("%d", &length);
			H = Initialize(length);
			printf("Ok\n");
			break;
		case 2:
			MakeEmpty(H);
			printf("Ok\n");
		case 3:
			printf("Please input the num you want to Insert\n");
			scanf_s("%d", &Element);
			Insert(Element, H);
			printf("Ok\n");
			break;
		case 4:
			printf("delete[%d]\n", DeleteMin(H));
			break;
		case 5:
			PrintHeap(H);
			printf("Ok\n");
			break;
		default:
			break;
		}
		printf("0.quit\n1.Initiate a Heap;\n2.Mkae the Heap Empty;\n3.Insert an elem\
\ent\n4.Delete the min\n5.Print the heap\n");
		scanf_s("%d", &flag);
	}
}
