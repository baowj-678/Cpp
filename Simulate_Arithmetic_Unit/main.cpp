#include <iostream>
#include "Num.h"

using namespace::std;


int main()
{
	Int a = -909;
	a.print_codes_binary();
	//Float c = 909;
	//c.print_codes_binary();
	Num* b = a.convert_to_float();
	b->print_codes_binary();
}