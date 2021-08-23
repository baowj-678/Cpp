#include<iostream>


using namespace::std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
	ListNode* last = head;
	ListNode* first = head;
	ListNode* second = head;
	ListNode* nextt = head;
	if (head && head->next)
	{
		first = head;
		second = head->next;
		nextt = second->next;

		head = second;
		second->next = first;
		first->next = nextt;

		last = first;

		while (last->next && last->next->next)
		{
			first = last->next;
			second = first->next;
			nextt = second->next;

			last->next = second;
			second->next = first;
			first->next = nextt;

			last = first;
		}
	}
	
	return head;
}

int main()
{
	int n;
	cin >> n;
	ListNode* head = NULL;
	for (int i(0); i < n; i++)
	{
		int x;
		cin >> x;
		ListNode* temp = new ListNode(x);
		temp->next = head;
		head = temp;
	}
	ListNode* temp = head;
	cout << "before" << endl;
	while (temp)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl << "after" << endl;
	head = swapPairs(head);
	temp = head;
	while (temp)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
}

//too slow
