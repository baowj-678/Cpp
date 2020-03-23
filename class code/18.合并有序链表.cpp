#include "ListNode.h"

ListNode* addSort(ListNode* head1, ListNode* head2)
{
	PNode head = NULL;
	PNode tail = NULL;
	while (head1 && head2)
	{
		if (head1->val < head2->val)
		{
			if (head == NULL)
			{
				head = head1;
				tail = head1;
			}
			else
			{
				tail->next = head1;
				tail = head1;
			}
			head1 = head1->next;
		}
		else
		{
			if (head == NULL)
			{
				head = head2;
				tail = head2;
			}
			else
			{
				tail->next = head2;
				tail = head2;
			}
			head2 = head2->next;
		}
	}
	if (head1)
	{
		tail->next = head1;
	}
	else
	{
		tail->next = head2;
	}
	return head;
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
	scanf_s("%d", &n);
	PNode head1 = NULL;
	for (int i(0); i < n; i++)
	{
		int x;
		scanf_s("%d", &x);
		PNode temp = createNode(x);
		temp->next = head1;
		head1 = temp;
	}
	print(head);
	print(head1);
	PNode head2 = addSort(head, head1);
	print(head2);

}