#ifndef _HASHQUAD_H_
#define _HASHQUAD_H_
#define MIN_TABLE_SIZE	2

typedef unsigned int Index;
typedef Index Position;
typedef int ElementType;

struct HashTbl;
typedef struct HashTbl* HashTable;

struct HashEntry;


Index Hash(ElementType Key, int TableSize);
int NextPrime(int TableSize);
typedef struct HashEntry Cell;
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P, HashTable H);
HashTable ReHash(HashTable H);

enum KindOfEntry{Legitimate, Empty, Deleted};

struct HashEntry
{
	ElementType Element;
	enum KindOfEntry Info;
};

struct HashTbl
{
	int TableSize;
	Cell* TheCells;
};
#endif // !_HASHQUAD_H_


