/*#include <iostream>
#include <list>

class arrList :public List<int> {

};*/

#include <stdio.h>


int main()
{
	int price = 0;
	printf_s("please in put the price:\n");
	scanf_s("%d", &price);
	int change = 100 - price;
	printf_s("give you %d RMB\n", price);

	return 0;
}