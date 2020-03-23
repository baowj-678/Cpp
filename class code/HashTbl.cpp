#include "HashTbl.h"
#include <malloc.h>
#include <stdio.h>

struct ListNode
{
	ElementType Element;
	Position Next;
};

struct HashTbl
{
	int TableSize;
	List* TheLists;
};

HashTable InitializeTable(int TableSize)
{
	HashTable H= (HashTable)malloc(sizeof(struct HashTbl));
	if (H == NULL)
	{
		printf("Space Overflow\n");
		return NULL;
	}
	H->TheLists = (List*)malloc(sizeof(struct ListNode) * TableSize);
}