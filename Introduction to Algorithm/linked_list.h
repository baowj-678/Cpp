#pragma once

typedef double element;
struct NODE;
typedef struct NODE Node;
typedef struct NODE* pNode;
pNode create_from_array(element nums[], int n);
bool del_linkde_list(pNode head);
pNode insert_to_head(pNode head, element x);
pNode insert_to_tail(pNode head, element x);
pNode linked_list_sort(pNode head);
void linked_list_print(pNode head);

struct NODE
{
	element val;
	struct NODE* next;
};
