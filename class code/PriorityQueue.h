#ifndef _PRIORITY_QUEUE_
#define _PRIORITY_QUEUE

struct HeapStruct;
typedef struct HeapStruct* PriorityQueue;
typedef int ElementType;
typedef int Position;

PriorityQueue Initialize(int MaxElement);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
bool IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
//heap sort
void PercolateDown(PriorityQueue H, Position p);
PriorityQueue BuildHeap(int* s, int n);
PriorityQueue HeapSort(int* s, int n);
void Print(PriorityQueue H);










#endif // !_PRIORITY_QUEUE_

