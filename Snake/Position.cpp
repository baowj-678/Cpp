#include"Position.h"
#include <malloc.h>
#include <random>
#include <time.h>

Ptr_position add(Ptr_position p, Ptr_direction d)
{
	p->X += d->X;
	p->Y += d->Y;
	return p;
}

Ptr_position create(Ptr_position p, Ptr_direction d)
{
	Ptr_position temp = (Ptr_position)malloc(sizeof(struct position));
	if (temp == NULL)
		return NULL;
	temp->X = p->X + d->X;
	temp->Y = p->Y + d->Y;
	return temp;
}

void Copy(Ptr_position a, Ptr_position b)
{
	a->X = b->X;
	a->Y = b->Y;
}

void Mul(Ptr_position a, int n)
{
	a->X *= n;
	a->Y *= n;
}
Ptr_position New_poi(int x, int y)
{
	Ptr_position APoi = (Ptr_position)malloc(sizeof(struct position));
	if (APoi != NULL)
	{
		APoi->X = x;
		APoi->Y = y;
	}
	return APoi;
}

border New_border(int p, int begin, int end)
{
	border ABoreder = (border)malloc(sizeof(struct Border));
	if (ABoreder != NULL)
	{
		ABoreder->begin = begin;
		ABoreder->end = end;
		ABoreder->p = p;
	}
	return ABoreder;
}

BorderLine New_BorderLine(int n, int x1, int y1, int x2, int y2, int direction)
{
	int i = 0;
	int delt;
	//水平
	if (direction == 0)
		delt = (x2 - x1) / n;
	//垂直
	else
		delt = (y2 - y1) / n;

	BorderLine head = NULL;
	//水平
	if (direction == 0)
	{
		int y;
		int lastX;
		int x = rand() % (delt) + x1;
		BorderLine temp = New_border(y1, x1, x);
		temp->next = head;
		head = temp;
		lastX = x;
		for (i = 1; i < n - 1; i++)
		{
			y = rand() % (y2 - y1) + y1;
			x = rand() % (delt) + x1 + i * delt;
			temp = New_border(y, lastX, x);
			lastX = x;
			temp->next = head;
			head = temp;
		}
		temp = New_border(y2, lastX, x2);
		temp->next = head;
		head = temp;
	}
	//垂直
	else if (direction == 1)
	{
		int x;
		int lastY;
		int y = rand() % (delt) + y1;
		BorderLine temp = New_border(x1, y1, y);
		temp->next = head;
		head = temp;
		lastY = y;
		for (i = 1; i < n; i++)
		{
			int y = rand() % delt + y1 + i * delt;
			int x = rand() % (x2 - x1) + x1;
			temp = New_border(x, lastY, y);
			lastY = y;
			temp->next = head;
			head = temp;
		}
		temp = New_border(x1, lastY, y2);
		temp->next = head;
		head = temp;
	}
	return head;
}

Ptr_position GenerateRandom(int x1, int y1, int x2, int y2)
{
	int x = rand() % (x2 - x1) + x1;
	int y = rand() % (y2 - y1) + y1;
	return New_poi(x, y);
}

int Is_Crash(Ptr_position a, Ptr_position b)
{
	if (abs(a->X - b->X) < 10 && abs(a->Y - b->Y) < 10)
	{
		return 1;
	}
	return 0;
}

void setNextDirc(Ptr_direction p, Ptr_position now)
{
	int dealt = 7;
	double sum = sqrt((p->X - now->X) * (p->X - now->X) + (p->Y - now->Y) * (p->Y - now->Y));
	int x = (int)(((p->X - now->X) / sum) * dealt);
	int y = (int)(((p->Y - now->Y) / sum) * dealt);
	
	p->X = x;
	p->Y = y;
}