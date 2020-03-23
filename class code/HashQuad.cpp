#include "HashQuad.h"
#include <malloc.h>

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;

	if (TableSize < MIN_TABLE_SIZE)
	{
		return NULL;
	}
	H = (HashTable)malloc(sizeof(struct HashTbl));
	if (H != NULL)
	{
		H->TableSize = NextPrime(H->TableSize);
		H->TheCells = (Cell*)malloc(sizeof(Cell) * H->TableSize);
		if (H->TheCells != NULL)
		{
			for (i = 0; i < H->TableSize; i++)
			{
				H->TheCells[i].Info = Empty;
			}
		}

	}
	return H;
}

Position Find(ElementType Key, HashTable H)
{
	Position CurrentPos;
	int CollisionNum = 0;

	CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCells[CurrentPos].Info != Empty &&
		H->TheCells[CurrentPos].Element != Key)
	{
		CurrentPos += 2 * ++CollisionNum - 1;
		if (CurrentPos >= H->TableSize)
			CurrentPos -= H->TableSize;
	}
	return CurrentPos;
}

void Insert(ElementType Key, HashTable H)
{
	Position Pos;
	Pos = Find(Key, H);
	if (H->TheCells[Pos].Info != Legitimate)
	{
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key;

	}
}

HashTable ReHash(HashTable H)
{
	int i, OldSize;
	Cell* OldCells;

	OldCells = H->TheCells;
	OldSize = H->TableSize;

	H = InitializeTable(2 * OldSize);
	for (i = 0; i < OldSize; i++)
	{
		if (OldCells[i].Info == Legitimate)
			Insert(OldCells[i].Element, H);
		free(OldCells + i);
	}
	return H;
}