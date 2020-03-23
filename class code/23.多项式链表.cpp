#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000
struct ListNode
{
	int ratio;
	int frequency;
	struct ListNode* next;
};
typedef struct ListNode* PtrToNode;
PtrToNode InsertRandom(PtrToNode head, int fre, int ratio);


int Exist[MAX];

PtrToNode CreateListRandom(int n, int fre, int ratio)
{
	PtrToNode Head = NULL;
	for (int i = 0; i < n; i++)
	{
		PtrToNode temp = (PtrToNode)malloc(sizeof(struct ListNode));
		temp->ratio = rand() % ratio + 1;
		int frequency = rand() % fre;
		while (Exist[frequency] != 0)
		{
			frequency = rand() % fre;
		}
		temp->frequency = frequency;
		Exist[frequency] = 1;
		temp->next = Head;
		Head = temp;
	}
	return Head;
}

PtrToNode CreateListSort(int n, int fre, int ratio)
{
	PtrToNode Head = NULL;
	for (int i = 0; i < n; i++)
	{
		int frequency = rand() % fre;
		while (Exist[frequency] != 0)
		{
			frequency = rand() % fre;
		}
		Exist[frequency] = 1;
	}
	for (int i = fre; i >= 0; i--)
	{
		if (Exist[i] == 1)
		{
			PtrToNode temp = (PtrToNode)malloc(sizeof(struct ListNode));
			temp->ratio = rand() % ratio + 1;
			temp->frequency = i;
			temp->next = Head;
			Head = temp;
		}
	}
	return Head;
}

PtrToNode MulRandom(PtrToNode head1, PtrToNode head2)
{
	PtrToNode head = NULL;
	while (head1)
	{
		PtrToNode head_temp = head2;
		while (head_temp)
		{
			head = InsertRandom(head, head1->frequency + head_temp->frequency, head1->ratio * head_temp->ratio);
			head_temp = head_temp->next;
		}
		head1 = head1->next;
	}
	return head;
}

PtrToNode MulSort(PtrToNode head1, PtrToNode head2)
{
	PtrToNode head = (PtrToNode)malloc(sizeof(struct ListNode));
	head->frequency = -1;
	head->ratio = 0;
	head->next = NULL;
	int fre = 0;
	int ratio = 0;
	while (head1)
	{
		PtrToNode head_temp = head2;
		PtrToNode head_main = head;
		while (head_temp)
		{
			fre = head1->frequency + head_temp->frequency;
			ratio = head1->ratio * head_temp->ratio;
			bool IsEqual = false;

			while (head_main->next)
			{
				if (head_main->next->frequency == fre)
				{
					head_main->next->ratio += ratio;
					IsEqual = true;
					break;
				}
				else if (head_main->next->frequency > fre)
				{
					PtrToNode temp = (PtrToNode)malloc(sizeof(struct ListNode));
					temp->frequency = fre;
					temp->ratio = ratio;
					temp->next = head_main->next;
					head_main->next = temp;
					IsEqual = true;
					break;
				}
				head_main = head_main->next;
				
			}
			if (IsEqual == false && head_main->next == NULL)
			{
				PtrToNode temp = (PtrToNode)malloc(sizeof(struct ListNode));
				temp->frequency = fre;
				temp->ratio = ratio;
				temp->next = head_main->next;
				head_main->next = temp;
			}
			head_temp = head_temp->next;
		}
		head1 = head1->next;
	}
	return head;
}

PtrToNode InsertRandom(PtrToNode head, int fre, int ratio)
{
	PtrToNode temp = head;
	while (temp)
	{
		if (temp->frequency == fre)
		{
			temp->ratio += ratio;
			return head;
		}
		temp = temp->next;
	}
	temp = (PtrToNode)malloc(sizeof(struct ListNode));
	temp->frequency = fre;
	temp->ratio = ratio;
	temp->next = head;
	head = temp;
	return head;
}

void print(PtrToNode head)
{
	while (head)
	{
		printf("[%d]-[%d]\n", head->ratio, head->frequency);
		head = head->next;
	}
}
void del(PtrToNode head)
{
	PtrToNode temp = head;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
int main()
{
	clock_t begin, end, sum = 0;
	int length = 0;
	for (int k = 1; k < 21; k++)
	{
		length = k * 15;
		sum = 0;
		for (int i = 0; i < 1000; i++)
		{
			Exist[i] = 0;
		}
		PtrToNode testRandom1 = CreateListRandom(length, MAX, 100);
		for (int i = 0; i < 1000; i++)
		{
			Exist[i] = 0;
		}
		PtrToNode testRandom2 = CreateListRandom(length, MAX, 100);
		for (int i = 0; i < 1; i++)
		{
			begin = clock();
			PtrToNode temp = MulRandom(testRandom1, testRandom2);
			end = clock();
			sum += (end - begin);
			del(temp);
		}
		del(testRandom1);
		del(testRandom2);

		printf("%d,%f;",length, (double)sum/CLOCKS_PER_SEC);
	}
	printf("\n");
	/*for (int k = 1; k < 21; k++)
	{
		length = k * 50;
		sum = 0;
		for (int i = 0; i < 1000; i++)
		{
			Exist[i] = 0;
		}
		PtrToNode testSort1 = CreateListSort(300, 1500, 100);
		for (int i = 0; i < 1000; i++)
		{
			Exist[i] = 0;
		}
		PtrToNode testSort2 = CreateListSort(length, 1500, 100);
		for (int i = 0; i < 30; i++)
		{
			begin = clock();
			PtrToNode temp = MulSort(testSort1, testSort2);
			end = clock();
			sum += (end - begin);
			del(temp);
		}
		del(testSort1);
		del(testSort2);
		printf("%d,%f;", length, (double)sum / CLOCKS_PER_SEC);
	}*/
	
	//print(testRandom);
}