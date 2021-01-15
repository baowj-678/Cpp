#include <iostream>

using namespace::std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {					//node is the point to the val you want to delete
	ListNode* temp = node->next;
	node->val = node->next->val;
	node->next = node->next->next;
	delete temp;
}

void clear(ListNode* node)
{
	ListNode* temp = NULL;
	while (node)
	{
		temp = node;
		node = node->next;
		delete temp;
	}
}

void print(ListNode* node)
{
	ListNode* temp = node;
	while (temp)
	{
		cout << temp->val << endl;
		temp = temp->next;
	}
}




int main()
{
	int x, num;
	ListNode* head = NULL;
	cin >> num;
	for (int i(0); i < num; i++)			//create a list
	{
		cin >> x;
		ListNode* temp = new ListNode(x);
		temp->next = head;
		head = temp;
	}

	print(head);
	clear(head);
}


//Í¨¹ý
