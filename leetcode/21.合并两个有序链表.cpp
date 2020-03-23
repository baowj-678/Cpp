#include <iostream>

using namespace::std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


ListNode* create()
{
	int n;
	int x;
	ListNode* head = NULL;
	cin >> n;
	for (int i(0); i < n; i++)
	{
		cin >> x;
		ListNode* temp = new ListNode(x);
		temp->next = head;
		head = temp;
	}
	return head;
}

ListNode* clear(ListNode* head)
{
	ListNode* temp = head;
	while (head)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	return NULL;
}

void print(ListNode* head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

}
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* head = NULL;
	if (l1 && l2 && l1->val <= l2->val)
	{
		head = l1;
		l1 = l1->next;
	}
	else if (l2)
	{
		head = l2;
		l2 = l2->next;
	}
	else if (l1)
	{
		head = l1;
		l1 = l1->next;
	}
	ListNode* last = head;
	while (l1 && l2)
	{
		if (l1->val <= l2->val)
		{
			last->next = l1;
			last = l1;
			l1 = l1->next;
		}
		else
		{
			last->next = l2;
			last = l2;
			l2 = l2->next;
		}
	}
	if (l1)
	{
		last->next = l1;
	}
	else if (l2)
	{
		last->next = l2;
	}
	return head;
}


int main()
{
	ListNode* l1 = create();
	ListNode* l2 = create();
	print(l1);
	print(l2);
	ListNode* l = mergeTwoLists(l1, l2);
	print(l);
	clear(l);
}

//通过，但时间太慢