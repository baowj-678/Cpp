#include <stdio.h>
#include <malloc.h>
#define MAX 1000
int People[MAX];

typedef struct ListNode {
	int Element;
	struct ListNode* Next;
	struct ListNode* Pre;
}* PtrToNode;


PtrToNode createNode(int Element)
{
	PtrToNode point = (PtrToNode)malloc(sizeof(struct ListNode));
	point->Element = Element;
	point->Next = NULL;
	point->Pre = NULL;
	return point;
}


//Á´±í
int Josephus_List(int step, PtrToNode head)
{
	if (head->Next == head)
		return head->Element;
	else
	{
		for (int i = 1; i < step; i++)
		{
			head = head->Next;
		}
		PtrToNode temp = head->Pre;
		temp->Next = head->Next;
		head->Next->Pre = temp;
		free(head);
		return Josephus_List(step, temp->Next);
	}
}

/*int Josephus(int n, int m)
{
	int Position = 0;
	int death = 1;
	while (death < n)
	{
		int pass = 0;
		while (pass < m)
		{
			Position++;
			Position %= n;
			if (People[Position] == 1)
			{
				pass++;
			}
		}
		People[Position] = 0;
		death++;
	}
	for (int i = 0; i < n; i++)
	{
		if (People[i] == 1)
			return (i + 1);
	}
	return -1;
}*/

/*void first_step(int* s, int n)
{
	for (int i = 0; i < n; i++)
	{
		s[i] = i + 1;
	}
	s[n - 1] = 0;
}
int Josephus(int n, int m)
{
	m--;
	int i = 0;
	int step = 0;
	while (People[i] != i)
	{
		step = 0;
		while (step != m)
		{
			i = People[i];
			step++;
		}
		People[i] = People[People[i]];
	}
	return i + 1;
}
*/

int main()
{
	
	int n;
	int step = 4;
	printf("Please input step:\n");
	scanf_s("%d", &step);
	printf("Please input the n:\n");
	scanf_s("%d", &n);

	PtrToNode head = NULL;
	PtrToNode tail = createNode(n);
	head = tail;
	for (int i = 1; i < n; i++)
	{
		PtrToNode temp = createNode(n - i);
		temp->Next = head;
		head->Pre = temp;
		head = temp;
	}
	tail->Next = head;
	head->Pre = tail;

	printf("%d",Josephus_List(step, head));
	
}