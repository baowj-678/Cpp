#pragma once
#include "Num.h"
#include <stdio.h>


/************************************* 数字超类 ******************************************/

Num::Num()
{
}

Num::~Num()
{
}

/**
* 将内存中的信息以二进制输出
* @param p: 起始地址
* @param n: 输出的位数
* @return void
*/
void Num::num_to_binary(void* p, int n)
{
	unsigned long long num = *(unsigned long long*)p;
	for (int i(0); i < n; i++)
		printf("%lld", (num >> (n - 1 - i)) & 1);
	printf("\n");
}

/************************************* 整数类 ******************************************/

Int::Int()
{
	// 是整数
	this->is_float = NumType::float_;
}

Int::~Int()
{
}

/************************************* 浮点数类 ******************************************/
Float::Float()
{
	this->is_float = NumType::float_;
}

Float::~Float()
{
}