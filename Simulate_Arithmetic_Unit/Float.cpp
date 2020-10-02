/**
* Float类的实现
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/10/2
*/

#pragma once
#include "Num.h"

const unsigned long long FLOAT_ONES = 0XFFFFFFFFFFFFFFFF;
const unsigned int E_BASE = 1023;

Float::Float()
{
	// 浮点数
	this->num_type = NumType::float_;
	// 补码
	this->code_type = CodeType::complement_;
	this->num.num = (double)0;
}

Float::Float(double num)
{
	// 浮点数
	this->num_type = NumType::float_;
	// 编码类型
	this->code_type = CodeType::complement_;
	this->num.num = num;
}

Float::Float(double num, CodeType type)
{
	// 浮点数
	this->num_type = NumType::float_;
	// 编码类型
	this->code_type = type;
	this->num.num = num;
}

Float::~Float()
{
}

/**
* 浮点数: 转原码
*/
void Float::convert_to_true_code()
{
	//正数
	if (this->num.s.f == 0)
	{
		this->code_type = CodeType::true_;
		return;
	}
	// 反码 -> 原码
	else if (this->code_type == CodeType::inverse_)
	{
		this->num.s.num ^= FLOAT_ONES;
	}
	// 补码 -> 原码
	else if (this->code_type == CodeType::complement_)
	{
		this->convert_to_inverse_code();
		this->convert_to_true_code();
	}
	this->code_type = CodeType::true_;
	return;
}

/**
* 浮点数: 转反码
*/
void Float::convert_to_inverse_code()
{
	// 正数
	if (this->num.s.f == 0)
	{
		this->code_type = CodeType::inverse_;
		return;
	}
	// 原码 -> 反码
	else if (this->code_type == CodeType::true_)
	{
		this->num.s.num ^= FLOAT_ONES;
	}
	// 补码 -> 反码
	else
	{
		this->num.s.num -= 1;
	}
	this->code_type = CodeType::inverse_;
	return;
}

/**
* 浮点数: 转补码
*/
void Float::convert_to_complement_code()
{
	if (this->num.s.f == 0)
	{
		this->code_type = CodeType::complement_;
		return;
	}
	// 原码  -> 补码
	else if (this->code_type == CodeType::true_)
	{
		this->convert_to_inverse_code();
		this->convert_to_complement_code();
	}
	// 反码 -> 补码
	else if (this->code_type == CodeType::inverse_)
	{
		this->num.s.num += 1;
	}
	this->code_type = CodeType::complement_;
	return;
}

/**
* 打印
*/
void Float::print_code_binary()
{
	this->num_to_binary(&this->num, 64);
}

/**
* 十进制打印数字
*/
void Float::print_num()
{
	printf("十进制为:%lf\n", this->num.num);
}
// 转浮点数
Float* Float::convert_to_float()
{
	return this;
}

// 转整数
Int* Float::convert_to_int()
{
	return NULL;
}