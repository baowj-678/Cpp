//#include <stdio.h>
#include "ListNode.h"


ListNode* findHalf(ListNode* head)
{
	PNode half = head;
	while ((head = head->next) && (head = head->next))
	{
		half = half->next;
	}
	return half;
}

int main()
{
	int n;
	scanf_s("%d", &n);
	PNode head = NULL;
	for (int i(0); i < n; i++)
	{
		int x;
		scanf_s("%d", &x);
		PNode temp = createNode(x);
		temp->next = head;
		head = temp;
	}
	print(head);
	PNode temp = findHalf(head);
	printf("\n");
	printf("%d", temp->val);
}