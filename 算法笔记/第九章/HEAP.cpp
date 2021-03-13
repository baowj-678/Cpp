/**
 * @file HEAP.cpp
 * @author Bao Wenjie
 * @brief 堆
 * @version 0.1
 * @date 2021-03-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

const int maxn = 100;

int heap[maxn];
int n;

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = a;
}


void downAdjust(int low, int high)
{
    int i = low;
    int j = i * 2;
    while(j < high)
    {
        if(j + 1 <= high && heap[j + 1] > heap[j])
        {
            j = j + 1;
        }

        if(heap[j] > heap[i])
        {
            swap(heap[j], heap[i]);
            i = j;
            j = i * 2;
        }
        else
            break;
    }
}

void createHeap()
{
    for(int i = n / 2; i >= 1; i--)
    {
        downAdjust(i, n);
    }
}

void deleteTop()
{
    heap[1] = heap[n--];
    downAdjust(1, n);
}

void upAdjust(int low, int high)
{
    int i = high;
    int j = i / 2;
    while(j >= low)
    {
        if(heap[j] < heap[i])
        {
            swap(heap[i], heap[j]);
            i = j;
            j = i / 2;
        }
        else
            break;
    }
}

void insert(int x)
{
    heap[++n] = x;
    upAdjust(1, n);
}


void heapSort()
{
    createHeap();
    for(int i = n; i > 1; i--)
    {
        swap(heap[i], heap[1]);
        downAdjust(1, i - 1);
    }
}