#include <iostream>
#include <string>

using namespace::std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* head  = NULL;
	string s;
	int put_forward = 0;
	while (l1 && l2)
	{
		int x = l1->val + l2->val + put_forward;
		put_forward = x / 10;
		x = x % 10;
		l1 = l1->next;
		l2 = l2->next;
		s.push_back(x);
	}
	while (l1)
	{
		int x = l1->val + put_forward;
		put_forward = x / 10;
		x = x % 10;
		l1 = l1->next;
		s.push_back(x);
	}
	while (l2)
	{
		int x = l2->val + put_forward;
		put_forward = x / 10;
		x = x % 10;
		l2 = l2->next;
		s.push_back(x);
	}
	if (put_forward)
		s.push_back(put_forward);

	for (int i(s.length() - 1); i >= 0; i--)
	{
		ListNode* temp = new ListNode(s[i]);
		temp->next = head;
		head = temp;
	}
	return head;
}

ListNode* create()
{
	int n;
	ListNode* head = NULL;
	cout << "please input the number of the numbers you want to input";
	cin >> n;
	for (int i(0); i < n; i++)
	{
		int x;
		cin >> x;
		ListNode* temp = new ListNode(x);
		temp->next = head;
		head = temp;
	}
	return head;
}

void print(ListNode* head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
}

void clear(ListNode* head)
{
	while (head)
	{
		ListNode* temp = head->next;
		delete head;
		head = temp;
	}
}
int main()
{
	ListNode* head1 = create();
	ListNode* head2 = create();
	ListNode* head = addTwoNumbers(head1, head2);

	print(head);
	clear(head1);
	clear(head2);
	clear(head);
}

//通过，但时间太慢