#include <iostream>
#include "Num.h"

using namespace::std;


int main()
{
	Float a = -157689.6;
	a.print_codes_binary();
	Int* b = a.convert_to_int();
	b->print_codes_binary();

}