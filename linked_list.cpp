#include <iostream>
#include "linked_list.h"

using namespace::std;
struct NODE
{
	element val;
	struct NODE* next;
};

pNode create_from_array(element nums[], int n)
{
	pNode head = NULL;
	for (int i(n - 1); i >= 0; i--)
	{
		pNode temp = new Node;
		if (temp != NULL)
		{
			temp->next = head;
			temp->val = nums[i];
			head = temp;
		}
		else
			return NULL;
	}
	return head;
}

bool del_linkde_list(pNode head);
pNode insert_to_head(pNode head, element x);
pNode insert_to_tail(pNode head, element x);
pNode linked_list_sort(pNode head)
{
	if (head == NULL)
		return NULL;
	pNode min_last = head;
	pNode now_last = head;
	pNode split = head;
	// first element
	for (; now_last->next != NULL; now_last = now_last->next)
	{
		if (min_last->next->val > now_last->next->val)
			min_last = now_last;
	}
	if (head->next != NULL && min_last->next->val < head->val)
	{
		split = min_last->next;
		min_last->next = split->next;
		split->next = head;
		head = split;
	}
	for (; split->next != NULL;)
	{
		for (now_last = split, min_last = split; now_last->next != NULL; now_last = now_last->next)
		{
			if (min_last->next->val > now_last->next->val)
				min_last = now_last;
		}
		pNode temp = min_last->next;
		min_last->next = temp->next;
		temp->next = split->next;
		split->next = temp;
		split = temp;
	}
	return head;
}

void linked_list_print(pNode head)
{
	for (; head != NULL; head = head->next)
	{
		cout << head->val << " ";
	}
	cout << endl;
	return;
}


