#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include "Queue.h"


SearchTree produceTree(int prefix[], int prefixBegin, int prefixEnd, int infix[], int infixBegin, int infixEnd)
{
	if (prefixBegin > prefixEnd || infixBegin > infixEnd)
	{
		return NULL;
	}


	Position tree = (Position)malloc(sizeof(struct TreeNode));

	int root = prefix[prefixBegin];
	int i;
	bool is_find = false;
	for (i = infixBegin; i <= infixEnd; i++)
	{
		if (root == infix[i])
		{
			break;
		}
	}

	tree->Element = root;
	int preMid = prefixBegin + i - infixBegin;
	tree->Left = produceTree(prefix, prefixBegin + 1, preMid, infix, infixBegin, i - 1);
	tree->Right = produceTree(prefix, preMid + 1, prefixEnd, infix, i + 1, infixEnd);
	return tree;
}

int i = 0;
void PrintInfix(SearchTree T, int s[])
{
	if (T == NULL)
		return;
	PrintInfix(T->Left, s);
	s[i++] = T->Element;
	PrintInfix(T->Right, s);
}

void PrintInfix(SearchTree T)
{
	if (T == NULL)
		return;
	PrintInfix(T->Left);
	printf("%d ", T->Element);
	PrintInfix(T->Right);
}

void PrintPrefix(SearchTree T, int s[])
{
	if (T == NULL)
		return;
	s[i++] = T->Element;
	PrintPrefix(T->Left, s);
	PrintPrefix(T->Right, s);
}

void PrintPrefix(SearchTree T)
{
	if (T == NULL)
		return;
	printf("%d ", T->Element);
	PrintPrefix(T->Left);
	PrintPrefix(T->Right);
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

void LevelTravelsal(SearchTree T, Queue Q)
{
	Enqueue(T, Q);
	while (!IsEmpty(Q))
	{
		SearchTree temp = Front(Q);
		printf("%d ", temp->Element);
		Dequeue(Q);
		if (temp->Left != NULL)
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


int main()
{
	clock_t begin, end, sum;
	Queue Q = CreateQueue(20000);
	int prefix[20000];
	int infix[20000];

	for (int z = 0; z <= 20000; z++)
	{
		prefix[z] = z;
		infix[z] = z;
	}

	for (int k = 1; k < 20; k++)
	{
		sum = 0;
		int n = k * 1000;
		//SearchTree temp = BuildTree(Q, n);

		for (int j = 0; j < 1000; j++)
		{
			begin = clock();
			SearchTree T = produceTree(prefix, 0, n-1, infix, 0, n-1);
			end = clock();
			sum += (end - begin);
			MakeEmpty(T);
		}
		printf("%d,%f;", n, (double)sum / CLOCKS_PER_SEC);
		MakeEmpty(Q);
	}
	
}