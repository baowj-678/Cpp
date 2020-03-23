#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include "Queue.h"

void LevelTravelsal(SearchTree T, Queue Q)
{
	Enqueue(T, Q);
	while (!IsEmpty(Q))
	{
		SearchTree temp = Front(Q);
		//printf("%d ", temp->Element);
		Dequeue(Q);
		if(temp->Left != NULL)
			Enqueue(temp->Left, Q);
		if (temp->Right != NULL)
			Enqueue(temp->Right, Q);
	}
}

SearchTree MakeEmpty(SearchTree T)
{
	/* my function
	if (T->Left != NULL)
		MakeEmpty(T->Left);
	if (T->Right != NULL)
		MakeEmpty(T->Right);
	free(T);
	return NULL;
	*/
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

SearchTree BuildTree(Queue Q, int Max)
{
	int n = 0;
	SearchTree root = (SearchTree)malloc(sizeof(struct TreeNode));
	root->Element = 0;
	root->Left = NULL;
	root->Right = NULL;
	Enqueue(root, Q);
	while (++n < Max)
	{
		SearchTree temp = Front(Q);
		Dequeue(Q);
		SearchTree left = (SearchTree)malloc(sizeof(struct TreeNode));
		SearchTree right = (SearchTree)malloc(sizeof(struct TreeNode));
		temp->Left = left;
		temp->Right = right;

		left->Element = n;
		left->Left = left->Right = NULL;
		right->Element = ++n;
		right->Left = right->Right = NULL;
		Enqueue(left, Q);
		Enqueue(right, Q);
	}
	return root;
}
int main()
{
	Queue Q = CreateQueue(20000);
	clock_t begin, end;
	
	for (int i = 1; i < 20; i++)
	{
		SearchTree T = BuildTree(Q, 1000*i);
		MakeEmpty(Q);
		begin = clock();
		for(int j = 0;j<1000;j++)
			LevelTravelsal(T, Q);
		end = clock();
		MakeEmpty(T);
		printf("%d,%f;", 1000 * i, (double)(end - begin) / CLOCKS_PER_SEC);
	}
}