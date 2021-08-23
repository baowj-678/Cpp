/**
 * Author: Bao Wenjie
 * Date: 2021/3/13
 * Link: https://leetcode-cn.com/problems/split-linked-list-in-parts/ 
 */ 


#include <iostream>
#include <vector>
using namespace::std;

 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
    	int n = 0;
    	ListNode* p = root;
    	while(p != NULL)
    	{
    		p = p->next;
    		n++;
		}
		int l = n / k;
		vector<ListNode*> ans; 
		for(int i = 0; i < k; i++)
		{
			int tmp_l = 0;
			if((k - i) * l == n)
			{
				tmp_l = l;
			}
			else
			{
				tmp_l = l + 1;
			}
			int cnt = 0;
			p = root;
			ans.push_back(root);
			while(++cnt < tmp_l)
			{
				p = p->next;
			}
			if(p == NULL)
			{
				root = NULL;
			}
			else
			{
				root = p->next;
				p->next = NULL;
			}
			n -= tmp_l;
		}
		return ans;
    }
};
