/**
* Float类的实现
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/10/2
*/

#pragma once
#include "Num.h"
#include <string>


Float::Float()
{
	// 浮点数
	this->num_type = NumType::float_;
	// 补码
	this->code_type = CodeType::true_;
	this->num.num = (double)0;
}

Float::Float(double num)
{
	// 浮点数
	this->num_type = NumType::float_;
	// 编码类型
	this->code_type = CodeType::true_;
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
* 浮点数原码乘法
* :param a: Float原数据
* :param b: Float原数据
*/
Float Float::multiply_true_code(Float a, Float b)
{
	// e为阶码的原码
	unsigned int Exponent = (a.get_exponent_true() + 1) + (b.get_exponent_true() + 1);
	unsigned long long A = a.get_decimal_true();
	unsigned long long B = b.get_decimal_true();
	unsigned long long Decimal = 0;
	while (A)
	{
		if (A & 1)
		{
			Decimal = Decimal + B;
		}
		Decimal >>= 1;
		A >>= 1;
	}
	while ((Decimal >> (Float::Decimal_Num)) == 0)
	{
		Decimal <<= 1;
		Exponent -= 1;
	}
	Float F;
	// 小数位
	F.set_decimal(Decimal);
	// 阶码位
	Exponent += (Float::E_BASE - 1);
	F.set_exponent(Exponent);
	// 符号位判断
	F.set_sign(a.get_sign() ^ b.get_sign());
	return F;
}

/**
* 浮点数补码乘法
* :param a: Float原数据
* :param b: Float原数据
*/
Float Float::multiply_complement_code(Float a, Float b)
{
	// e为阶码的原码
	unsigned int Exponent = (a.get_exponent_true() + 1) + (b.get_exponent_true() + 1);
	unsigned long long A = a.get_decimal_complement();
	double B_tmp = (double)b.get_num();
	unsigned long long B_ = b.get_decimal_complement();
	unsigned long long B = b.get_decimal_complement();
	unsigned long long Decimal = 0;
	while (A)
	{
		if (A & 1)
		{
			Decimal = Decimal + B;
		}
		Decimal >>= 1;
		A >>= 1;
	}
	while ((Decimal >> (Float::Decimal_Num)) == 0)
	{
		Decimal <<= 1;
		Exponent -= 1;
	}
	Float F;
	// 小数位
	F.set_decimal(Decimal);
	// 阶码位
	Exponent += (Float::E_BASE - 1);
	F.set_exponent(Exponent);
	// 符号位判断
	F.set_sign(a.get_sign() ^ b.get_sign());
	return F;
}

/**
* 浮点数: 转原码
*/
void Float::convert_to_true_code()
{
	//正数
	if (this->num.s.sign == 0)
	{
		this->code_type = CodeType::true_;
		return;
	}
	// 反码 -> 原码
	else if (this->code_type == CodeType::inverse_)
	{
		this->num.s.decimal ^= FLOAT_ONES;
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
	if (this->num.s.sign == 0)
	{
		this->code_type = CodeType::inverse_;
		return;
	}
	// 原码 -> 反码
	else if (this->code_type == CodeType::true_)
	{
		this->num.s.decimal ^= FLOAT_ONES;
	}
	// 补码 -> 反码
	else
	{
		this->num.s.decimal -= 1;
	}
	this->code_type = CodeType::inverse_;
	return;
}

/**
* 浮点数: 转补码
*/
void Float::convert_to_complement_code()
{
	if (this->num.s.sign == 0)
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
		this->num.s.decimal += 1;
	}
	this->code_type = CodeType::complement_;
	return;
}

/**
* 打印
*/
void Float::print_code_binary()
{
	// 打印符号位
	this->num_to_binary(&this->num, 64, 63);
	printf(" ");
	// 打印阶码
	this->num_to_binary(&this->num, 63, 52);
	printf(" ");
	// 打印小数
	this->num_to_binary(&this->num, 52, 0);
	printf("\n");
}

/**
* 十进制打印数字
*/
void Float::print_num()
{
	// 转补码
	this->convert_to_true_code();
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
	u_int int_num;
	int_num.num = 0;
	this->convert_to_true_code();
	// e: 保存阶码
	unsigned int e = this->num.s.exponent;
	// x第一位置1
	int_num.s.decimal |= 0X40000000;
	// x其余位取小数前30位
	int_num.s.decimal |= (this->num.s.decimal >> 22);
	// 向左移
	if (e >= E_BASE)
	{
		e = e - E_BASE;
		// 如果左移不足30
		if (e < 30)
		{
			int_num.num >>= (30 - e);
		}
		// 否则
		else
		{
			e -= 30;
			int_num.num <<= e;
		}

	}
	// 向右移（为0）
	else
	{
		int_num.s.decimal = 0;
	}
	// 符号位
	if (this->num.s.sign == 0)
		int_num.s.sign = 0;
	else
		int_num.s.sign = 1;
	Int* ans = new Int(int_num.num, CodeType::true_);
	return ans;
}

/**
* 获取十进制数字的字符串
*/
string Float::get_string()
{
	string ans = "";
	ans += std::to_string(this->num.num);
	return ans;
}


/**
* << 重载
*/
ostream& operator<<(ostream& os, Float num)
{
	os << num.get_string();
	return os;
}

/**
* 获取num(将double变成long long,二进制存储不变)
*/
long long Float::get_num()
{
	long long ans = 0;
	ans |= (this->num.s.sign << 63);
	ans |= (this->num.s.exponent << 51);
	ans |= this->num.s.decimal;
	return ans;
}

/**
* 获取符号位
*/
unsigned int Float::get_sign()
{
	return this->num.s.sign;
}

/**
* 获取数字位(原码/原存储形式)
*/
unsigned long long Float::get_decimal()
{
	this->convert_to_true_code();
	return (unsigned long long)this->num.s.decimal;
}

// 获取小数部分(0.x形式)
unsigned long long Float::get_decimal_true()
{
	this->convert_to_true_code();
	return (this->num.s.decimal | ((unsigned long long)0b1 << Float::Decimal_Num));
}



/**
* 获取小数部分(补码形式/双符号形式)
*/
unsigned long long Float::get_decimal_complement()
{
	this->convert_to_complement_code();
	unsigned long long tmp = this->num.s.decimal;
	if (this->num.s.sign == 1)
	{
		// 负数
		tmp = tmp | (unsigned long long)0b11 << (Float::Decimal_Num + 1);
	}
	else
	{
		// 正数
		tmp = tmp | (unsigned long long)0b00 << (Float::Decimal_Num + 1);
	}
	return tmp;
}

/**
* 获取阶码(移码/硬件存储形式)
*/
unsigned int Float::get_exponent()
{
	return this->num.s.exponent;
}


/**
* 获取阶码(原码)
*/
unsigned int Float::get_exponent_true()
{
	return (unsigned int)this->num.s.exponent - Float::E_BASE;
}

/**
* 设置阶码(移码/硬件存储形式)
*/
void Float::set_exponent(unsigned long long e)
{
	this->num.s.exponent = e;
}

/**
* 设置小数(原码/硬件存储形式)
*/
void Float::set_decimal(unsigned long long x)
{
	this->num.s.decimal = x;
}

/**
* 设置符号位(0-1/硬件存储形式)
*/
void Float::set_sign(unsigned int sign)
{
	this->num.s.sign = sign;
}
