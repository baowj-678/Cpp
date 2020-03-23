#include "HashSep.h"
#include <stdio.h>
#include <malloc.h>

//
Index Hash(const int Key, int TableSize)
{
}
//


int NextPrime(int x)
{
	return x;
}


HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;
	if (TableSize < MIN_TABLE_SIZE)
	{
		printf("Table size too small\n");
		return NULL;
	}

	H = (HashTable)malloc(sizeof(struct HashTbl));
	if (H != NULL)
	{
		H->TableSize = NextPrime(TableSize);
		H->TheLists = (List*)malloc(sizeof(List) * H->TableSize);
		if (H->TheLists != NULL)
		{
			for (i = 0; i < H->TableSize; i++)
			{
				H->TheLists[i] = (List)malloc(sizeof(struct ListNode));
				if (H->TheLists[i] != NULL)
				{
					H->TheLists[i]->Next = NULL;
				}
			}
		}
	}
	return H;
}

Position Find(ElementType Key, HashTable H)
{
	Position P;
	List L;

	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L->Next;
	while (P != NULL && P->Element != Key)
	{
		P = P->Next;
	}
	return P;
}

void Insert(ElementType Key, HashTable H)
{
	Position Pos, NewCell;
	List L;

	Pos = Find(Key, H);
	if (Pos == NULL)
	{
		NewCell = (Position)malloc(sizeof(struct ListNode));
		if (NewCell != NULL)
		{
			L = H->TheLists[Hash(Key, H->TableSize)];
			NewCell->Next = L->Next;
			NewCell->Element = Key;
			L->Next = NewCell;
		}
	}
}