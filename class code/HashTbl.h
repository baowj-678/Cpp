#ifndef _HASH_TABLE_
#define _HASH_TABLE_
struct ListNode;
typedef int ElementType;
typedef struct ListNode* Position;
typedef Position List;
struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitializeTable(int TableSize);

#endif // !_HASH_TABLE_
