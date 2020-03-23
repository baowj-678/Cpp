#include "Queue.h"
#include <malloc.h>
#include <stdio.h>

struct QueueRecord
{
	int Capacity;	//the size of array
	int Front;		//the first
	int Rear;		//the last
	int Size;		//the size of the queue now
	ElementType* Array;
};

const static ElementType Error = 0;

bool IsEmpty(Queue Q)
{
	return Q->Size == 0;
}

bool IsFull(Queue Q)
{
	return Q->Capacity == Q->Size;
}

Queue CreateQueue(int MaxElements)
{
	Queue Q = (Queue)malloc(sizeof(struct QueueRecord));
	if (Q == NULL)
		return Q;
	else
	{
		ElementType* array = (ElementType*)malloc(sizeof(ElementType) * MaxElements);
		Q->Array = array;
		Q->Capacity = MaxElements;
		MakeEmpty(Q);
	}
	return Q;
}
void DisposeQueue(Queue Q)
{
	if(Q->Array)
		free(Q->Array);
	if(Q)
		free(Q);
}
void Enqueue(ElementType X, Queue Q)
{
	if (!IsFull(Q))
		Q->Size++;
		Q->Rear = (Q->Rear + 1) % Q->Capacity;
		Q->Array[Q->Rear] = X;
}
void MakeEmpty(Queue Q)
{
	Q->Front = 1;
	Q->Rear = 0;
	Q->Size = 0;
}
ElementType Front(Queue Q)
{
	if (!IsEmpty(Q))
		return Q->Array[Q->Front];
	return Error;
}
ElementType FrontAndDequeue(Queue Q)
{
	ElementType t = Front(Q);
	Dequeue(Q);
	return t;
}
void Dequeue(Queue Q) 
{
	if (!IsEmpty(Q))
	{
		Q->Front = (Q->Front + 1) % Q->Capacity;
		Q->Size--;
	}
}

/*int main()
{
	printf("c.create a queue;\nd.delete a queue\nm.make queue\
 empty\ne.enqueue an element\no.dequeue an element\nq.quit\n");
	char action;
	Queue q = NULL;
	ElementType x;
	scanf_s("%c", &action);
	getchar();
	while (action != 'q')
	{
		switch (action)
		{
		case 'c':
			printf("please input size of array:\n");
			int n;
			scanf_s("%d", &n);
			getchar();
			q = CreateQueue(n);
			printf("successfully create a queue of [%d] size\n", n);
			break;

		case 'd':
			if(q)
				DisposeQueue(q);
			printf("delete the queue successfully!\n");
			break;

		case 'm':
			MakeEmpty(q);
			printf("make empty successfully!\n");
			break;

		case 'e':
			printf("please input the element to enqueue:\n");
			scanf_s("%d", &x);
			getchar();
			Enqueue(x, q);
			printf("[%d], enqueue successfully!\n", x);
			break;

		case 'o':
			x = Front(q);
			Dequeue(q);
			printf("[%d] successfully dequeue!\n", x);
			break;
		case 'p':
			printf("front:%d, rear:%d\n", q->Front, q->Rear);
			break;

		default:
			break;
		}
		printf("c.create a queue;\nd.delete a queue\nm.make queue\
 \empty\ne.enqueue an element\no.dequeue an element\nq.quit\n\n");
		scanf_s("%c", &action);
		getchar();

	}
	DisposeQueue(q);
	printf("quit successfully!\n");
	
	

}*/