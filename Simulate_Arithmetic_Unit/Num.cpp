#pragma once
#include "Num.h"
#include <stdio.h>
#include <iostream>

using namespace::std;
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
* @param high: 高地址位（不包括）
* @param low: 低地址位（包括）
* @return void
*/
void Num::num_to_binary(void* p, int high, int low)
{
	unsigned long long num = *(unsigned long long*)p;
	for (int i(high - 1); i >= low; i--)
		printf("%lld", (num >> i) & 1);
}

/**
* 打印原码、反码、补码
*/
void Num::print_codes_binary()
{
	this->print_num();
	printf("原码:\n");
	this->convert_to_true_code();
	this->print_code_binary();
	printf("反码:\n");
	this->convert_to_inverse_code();
	this->print_code_binary();
	printf("补码:\n");
	this->convert_to_complement_code();
	this->print_code_binary();
}

