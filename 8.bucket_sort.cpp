#include "linked_list.h"
#include "basic_array_function.h"
#include <iostream>

using namespace::std;

int main()
{
	int n = 90;
	element* nums = array_generate(n);
	array_print(nums, n);
	pNode head = create_from_array(nums, n);
	linked_list_print(head);
	linked_list_sort(head);
	linked_list_print(head);
}