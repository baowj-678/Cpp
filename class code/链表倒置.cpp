#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

/*
就地逆置法

先假定有一个函数，可以将以head为头结点的单链表逆序，并返回新的头结点。
利用这个函数对问题进行求解：将链表分为当前表头结点和其余部分，递归的过程就是，
先将表头结点从链表中拆出来，然后对其余部分进行逆序，最后将当前的表头结点链接到逆序链表的尾部。
递归的终止条件就是链表只剩一个节点时，直接返回这个节点。
*/



Node* CreatList()
{
	int n;
	scanf_s("%d", &n);
	Node* head = NULL;
	Node* tail = head;

	int x;
	scanf_s("%d", &x);
	struct node* temp;
	temp = (Node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;

	head = temp;
	tail = temp;

	int i;
	for (i = 1; i < n; i++)
	{
		scanf_s("%d", &x);
		temp = (Node*)malloc(sizeof(struct node));
		temp->data = x;
		temp->next = NULL;

		tail->next = temp;
		tail = temp;
	}
	return head;
}

void ShowList(Node* phead)
{
	while (phead != NULL)
	{
		printf("%d ", phead->data);
		phead = phead->next;
	}
	printf("\n");
}

Node* ReverseList(Node* phead)
{
	if (phead->next == NULL)
		return phead;

	Node* temp = phead->next;
	phead->next = NULL;
	Node* tail = temp;
	Node* New = ReverseList(temp);

	if(tail!=NULL)
		tail->next = phead;

	return New;
}

int main(void)
{
	Node* phead;
	phead = CreatList();
	printf("链表逆置前的数据:\n");
	ShowList(phead);
	phead = ReverseList(phead);
	printf("链表逆置后的数据:\n");
	ShowList(phead);
	return 0;
}