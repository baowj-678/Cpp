#ifndef _HASHSEP_H_
#define _HASHSEP_H_
#define MIN_TABLE_SIZE	2

struct ListNode;
struct HashTbl;
typedef unsigned int Index;
typedef struct ListNode* Position;
typedef Position List;
typedef int ElementType;
typedef HashTbl* HashTable;

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


Index Hash(const int Key, int TableSize);
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P);
int NextPrime(int x);


#endif // !_HASHSEP_H_
