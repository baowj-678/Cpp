#include "SortAlgorithm.h"
#include "basic_array_function.h"
#include <iostream>
#include <time.h>

using namespace::std;
int space[8][10000];
//int main()
//{
//	clock_t begin, end;
//	int n = 21;
//	double* nums = array_generate_double<double>(20 * 500, 0, 7.8);
//	pNode head = create_from_array(nums, 20 * 500);
//	double* test = new double[20 * 500];
//	double time = 0;
//	pNode temp = head;
//	int j = 0;
//	for (int i(20); i > 0; --i)
//	{
//		time = 0;
//		int m = i * 500;
//		for (int k = 0; k < 50; k++)
//		{
//			for (j = 0, temp = head; j < m; j++, temp=temp->next)
//				temp->val = nums[j];
//			if (temp)
//				temp->next = NULL;
//			begin = clock();
//			head = bucket_sort(head);
//			end = clock();
//			time += ((double)end - begin);
//		}
//		cout << time/CLOCKS_PER_SEC << ",";
//	}
//	delete[] nums;
//}