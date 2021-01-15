#include <iostream>

using namespace::std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* temp = head;
	int i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	if (n == i)
	{
		return head->next;
	}
	else
	{
		i = i - n - 1;
		temp = head;
		for (; i > 0; i--)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		return head;
	}
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
int main()
{
	int n;
	cout << "please input n:" << endl;
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
	print(head);
	head = removeNthFromEnd(head, 1);
	print(head);

}
//accepted but slow