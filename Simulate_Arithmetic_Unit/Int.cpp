/**
* Int类的实现
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/10/2
*/

#pragma once
#include "Num.h"
#include <string>

const unsigned int ONES = 0X7FFFFFFF; //01..31..1
const unsigned int FFFF = 0XFFFFFFFF; //111111111
const unsigned long long FLOAT_ONES = 0XFFFFFFFFFFFFFFFF;
const unsigned int E_BASE = 1023;

Int::Int()
{
	// 整数
	this->num_type = NumType::int_;
	// 补码
	this->code_type = CodeType::complement_;
	this->num.num = 0;
}

Int::Int(int num)
{
	// 整数
	this->num_type = NumType::int_;
	// 补码
	this->code_type = CodeType::complement_;
	this->num.num = num;
}

Int::Int(int num, CodeType type)
{
	// 整数
	this->num_type = NumType::int_;
	// 补码
	this->code_type = type;
	this->num.num = num;

}

Int::~Int()
{
}

/**
* 整数: 转反码
*/
void Int::convert_to_inverse_code()
{
	// 原码 -> 反码
	if (this->code_type == CodeType::true_)
	{
		// 负数
		if (this->num.s.sign != 0)
		{
			this->num.s.decimal ^= ONES;
		}
	}
	// 补码 -> 反码
	else if (this->code_type == CodeType::complement_)
	{
		// 负数
		if (this->num.s.sign != 0)
		{
			this->num.s.decimal -= 1;
		}
	}
	// 反码 -> 反码
	else
	{
		return;
	}
	this->code_type = CodeType::inverse_;
	return;
}

/**
* 整数: 转原码
*/
void Int::convert_to_true_code()
{
	// 反码 -> 原码
	if (this->code_type == CodeType::inverse_)
	{
		// 负数
		if (this->num.s.sign != 0)
		{
			this->num.s.decimal ^= ONES;
		}
	}
	// 补码 -> 原码
	else if (this->code_type == CodeType::complement_)
	{
		// 负数
		if (this->num.s.sign != 0)
		{
			this->convert_to_inverse_code();
			this->convert_to_true_code();
		}
	}
	// 原码 -> 原码
	else
	{
		return;
	}
	this->code_type = CodeType::true_;
	return;
}

/**
* 整数: 转补码
*/
void Int::convert_to_complement_code()
{
	// 原码 -> 补码
	if (this->code_type == CodeType::true_)
	{
		this->convert_to_inverse_code();
		this->convert_to_complement_code();
	}
	// 反码 -> 补码
	else if (this->code_type == CodeType::inverse_)
	{
		// 负数
		if (this->num.s.sign != 0)
		{
			this->num.s.decimal += 1;
		}
	}
	// 补码 -> 补码
	else
	{
		return;
	}
	this->code_type = CodeType::complement_;
	return;
}

/**
* 按照二进制打印数字
*/
void Int::print_code_binary()
{
	// 符号位
	this->num_to_binary(&this->num.num, 32, 31);
	printf(" ");
	// 数字位
	this->num_to_binary(&this->num.num, 31, 0);
	printf("\n");
}

/**
* 十进制打印数字
*/
void Int::print_num()
{
	// 转补码
	this->convert_to_complement_code();
	printf("十进制为:%d\n", this->num.num);
}

/**
* 转浮点数
*/
Float* Int::convert_to_float()
{
	this->convert_to_true_code();
	u_float num;
	// 符号位
	num.s.sign = this->num.s.sign;
	// 阶码10010101000001010001111010111000010100011110101110001
	unsigned long long tmp = this->num.s.decimal;
	unsigned long long i = 0;
	while (tmp > 1)
	{
		tmp >>= 1;
		i++;
	}
	tmp = this->num.s.decimal;
	num.s.exponent = i + E_BASE;
	// 小数
	num.s.decimal = (tmp << (52 - i));
	// new对象
	Float* ans = new Float(num.num, CodeType::true_);
	return ans;
}

/**
* 转整数
*/
Int* Int::convert_to_int()
{
	return this;
}

/**
* 获取十进制数字的字符串
*/
string Int::get_string()
{
	string ans = "";
	ans += std::to_string(this->num.num);
	return ans;
}

/**
* << 重载
*/
ostream& operator<<(ostream& os, Int num)
{
	os << num.get_string();
	return os;
}

/**
* 获取num
*/
long long Int::get_num()
{
	long long ans = 0;
	ans |= this->num.num;
	return ans;
}

/**
* 获取符号位
*/
unsigned int Int::get_sign()
{
	return this->num.s.sign;
}

/**
* 获取数字位
*/
unsigned long long Int::get_decimal()
{
	return this->num.s.decimal;
}

/**
* 获取阶码
*/
unsigned int Int::get_exponent()
{
	return 0;
}

/**
* + 重载
*/
Int Int::operator+(Int& num)
{
	// 获取A的补码
	this->convert_to_complement_code();
	long long a = this->get_num();
	// 获取B的补码
	num.convert_to_complement_code();
	long long b = num.get_num();
	int s = 0;
	int c = 0;
	for (int i(0); i < 32; i++)
	{
		int a_ = (a >> i) & 1;
		int b_ = (b >> i) & 1;
		// 本位和
		int c1 = (a_) ^ (b_) ^ s;
		// 进位
		s = (a_ & b_) | (a_ & s) | (b_ & s);
		// 
		c |= (c1 << i);
	}
	Int ans = { c, CodeType::complement_ };
	return ans;
}