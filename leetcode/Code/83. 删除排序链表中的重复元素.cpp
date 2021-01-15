/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3

*/

#include <iostream>

using namespace::std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createNode(void)
{
	ListNode *head = NULL;
	int n;
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

ListNode* deleteDuplicates(ListNode* head) {
	ListNode* point = head;
	while (point)
	{
		while (point->next && point->val == point->next->val)
		{
			ListNode* temp = point->next->next;
			delete point->next;
			point->next = temp;
		}
		if(point)
			point = point->next;
	}
	return head;
}


int main()
{
	ListNode* head = createNode();
	ListNode* i = head;
	while (i)
	{
		cout << i->val;
		i = i->next;
	}
	head = deleteDuplicates(head);
	cout << endl;
	while (head)
	{
		cout << head->val;
		head = head->next;
	}
}

//accepted