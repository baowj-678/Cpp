#include "linked_list.h"
#include "basic_array_function.h"
#include <iostream>

using namespace::std;

pNode bucket_sort(pNode head);
int main()
{
	cout << "Bucket sort:\n" << "n:\n";
	int n;
	cin >> n;
	double nums[100];
	for (; n != 0;)
	{
		for (int i(0); i < n; i++)
			cin >> nums[i];
		pNode head = create_from_array(nums, n);
		head = bucket_sort(head);
		cout << "ans:\n";
		linked_list_print(head);
		cout << "n:\n";
		cin >> n;
	}
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
	bool is_head = false;
	for (i = 0; i < n - 1; i++)
	{
		if (bucket_head[i] == NULL)
		{
			continue;
		}
		else
		{
			if (is_head == false)
			{
				is_head = true;
				head = bucket_head[i];
			}
		}
		for (temp = bucket_head[i]; temp->next != NULL; temp = temp->next)
			;
		for (int j(i + 1); j < n; j++)
		{
			if (bucket_head[j] != NULL)
			{
				temp->next = bucket_head[j];
				break;
			}
		}
	}
	if (bucket_head != NULL)
		delete[] pNode(bucket_head);
	return head;
}