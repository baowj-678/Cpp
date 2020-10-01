#include <iostream>
#include "Num.h"

using namespace::std;


int main()
{
	int a = -899;
	//u_int b;
	//b.x = 9;
	//printf("%d", b.s.x);
	Num::num_to_binary(&a, 32);
	for (int i(0); i < 32; i++)
		printf("%d", (a >> (31- i)) & 1);

}