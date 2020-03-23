#include <stdio.h>

static int fast[12];

int BakeSweetPotato(int n)
{
	if (1 >= n)
	{
		fast[1 - 1] = 99999;
		return 99999;
	}
	if (2 == n)
	{
		fast[2 - 1] = 1;
		return 1;
	}
	if (5 == n)
	{
		fast[5 - 1] = 1;
		return 1;
	}

	int five, two;
	if (fast[n - 5] != 0)
		five = fast[n - 5] + 1;
	else
		five = BakeSweetPotato(n - 5) + 1;
	if (fast[n - 2])
		two = fast[n - 2] + 1;
	else
		two = BakeSweetPotato(n - 2) + 1;

	if (five > two)
	{
		fast[n - 1] = two;
		return two;
	}
	else
	{
		fast[n - 1] = five;
		return five;
	}
	
}

int main()
{
	printf("%d\n", BakeSweetPotato(19));
}