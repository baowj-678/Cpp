#ifndef _QUEUE_H_
#define _QUEUE_H_

struct TreeNode;
typedef struct TreeNode* SearchTree;
typedef struct TreeNode* Position;
struct TreeNode
{
	int Element;
	SearchTree Left;
	SearchTree Right;
};

struct QueueRecord;
typedef struct QueueRecord* Queue;
typedef SearchTree ElementType;

bool IsEmpty(Queue Q);
bool IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif // !_QUEUE_H_
