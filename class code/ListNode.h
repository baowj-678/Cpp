#ifndef _LIST_NODE_
#define _LIST_NODE_

#include <malloc.h>
#include <stdio.h>

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

struct Node {
	ElementType Element;
	Position Next;
};


typedef int ElementType;

List MakeEmpty(List L);		//
bool IsEmpty(List L);
bool IsLast(Position P, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L, Position P);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

typedef struct ListNode {
	ElementType val;
	ListNode* next;
}* PNode;


PtrToNode createNode(ElementType val);//create a node return it's point
void del(ListNode* head);
void print(ListNode* head);



#endif // !_LIST_NODE_
