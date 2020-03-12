#include "linked_list.h"
#include "basic_array_function.h"
#include <iostream>

using namespace::std;

pNode bucket_sort(pNode head);
int main()
{
	int n = 100;
	// generate a random n-long array
	element* nums = array_generate_double(n, 0, 8);
	array_print(nums, n);
	// create a linked-list from the random array
	pNode head = create_from_array(nums, n);
	linked_list_print(head);
	head = bucket_sort(head);
	linked_list_print(head);
}

pNode bucket_sort(pNode head)
{
	if (head == NULL)
		return NULL;
	// find the max number
	double max = head->val;
	pNode temp = head;
	pNode now = NULL;
	int i = 0;
	for (; temp->next != NULL; temp = temp->next)
	{
		if (temp->val > max)
			max = temp->val;
	}
	int n = (int)(max + 1);
	// init a array to store pNode
	pNode* bucket_head = new pNode[n];
	if (bucket_head != NULL)
	{
		for (i = 0; i < n; i++)
		{
			bucket_head[i] = NULL;
		}
	}
	// put nums into bucket
	for (temp = head; temp != NULL; )
	{
		now = temp;
		temp = temp->next;
		i = (int)(now->val);
		now->next = bucket_head[i];
		bucket_head[i] = now;
	}
	// sort every bucket
	for (i = 0; i < n; i++)
	{
		bucket_head[i] = linked_list_sort(bucket_head[i]);
	}
	// put out the bucket
	n--;
	for (i = 0; i < n; i++)
	{
		for (temp = bucket_head[i]; temp->next != NULL; temp = temp->next)
			;
		if (temp != NULL)
			temp->next = bucket_head[i + 1];
	}
	temp = bucket_head[0];
	if (bucket_head != NULL)
		delete(bucket_head);
	return temp;
}