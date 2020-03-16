#pragma once
#ifndef SORT_ALGORITHM
#define SORT_ALGORITHM
#include "linked_list.h"

//insert sort
void insertSort(int* s, int n);
int main_insert_sort();

//merge sort
void mergeSort(int s[], int begin, int end);
int main_merge_sort();

//radix sort
int* radix_sort(int* sum, int n, int space[8][100]);
int main_radix_sort();

//counting sort
int counting_sort(int* s, int n);
int main_counting_sort();

//bucket sort
pNode bucket_sort(pNode head);
int main_bucket_sort();

#endif // !SORT_ALGORITHM

