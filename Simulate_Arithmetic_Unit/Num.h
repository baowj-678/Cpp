/**
* Num类，Int类、Float类的定义
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/10/2
*/

#pragma once
#include "INT.h"
#include "FLOAT.h"
#include <iostream>
#include <ostream>
#include <string.h>

using std::ostream;
using std::istream;
using std::string;
using std::operator+;
using std::operator-;

/**
* 数字类别【浮点数、整数】
*/
enum class NumType
{
	int_ = 1,
	float_ = 2
};

/**
* 编码类别【原码、反码、补码】
*/
enum class CodeType
{
	true_ = 1,
	inverse_ = 2,
	complement_ = 3
};

/**
* 数字超类
*/
class Num;

/**
* 整数类
*/
class Int;

/**
* 浮点数类
*/
class Float;

/************************************* 数字超类 ******************************************/
class Num
{
public:
	Num();
	~Num();
	/***** 变量 *****/
	// 数字类型标识符
	NumType num_type;
	// 编码类型标识符
	CodeType code_type;

	/***** 抽象方法 *****/
	// 转原码
	virtual void convert_to_true_code() = 0;
	// 转反码
	virtual void convert_to_inverse_code() = 0;
	// 转补码
	virtual void convert_to_complement_code() = 0;
	// 转整数
	virtual Int* convert_to_int() = 0;
	// 转浮点数
	virtual Float* convert_to_float() = 0;
	// 二进制打印数字
	virtual void print_code_binary() = 0;
	// 十进制打印数字
	virtual void print_num() = 0;
	// 获取整个数
	virtual long long get_num() = 0;
	// 获取符号位
	virtual long long get_sign() = 0;
	// 获取数字位
	virtual long long get_x() = 0;
	// 获取阶码位
	virtual long long get_e() = 0;

	/***** 静态方法 *****/
	// 输出数字存储的二进制形式
	static void num_to_binary(void* p, int high, int low = 0);

	/***** 普通方法 *****/
	// 打印所有编码情况
	void print_codes_binary();	

	/***** 友元方法 *****/
	// << 重载
	friend ostream& operator<<(ostream& os, Num* num);



};


/************************************* 整数类 ******************************************/
class Int : public Num
{
public:
	Int();
	Int(int num);
	Int(int num, CodeType type);
	~Int();

private:
	// 数字
	u_int num;

public:
	// 转原码
	void convert_to_true_code();
	// 转反码
	void convert_to_inverse_code();
	// 转补码
	void convert_to_complement_code();
	// 转浮点数
	Float* convert_to_float();
	// 转整数
	Int* convert_to_int();
	// 输出数字
	string get_string();

	// 打印数字
	void print_code_binary();
	// 十进制打印数字
	void print_num();
	// 获取整个数
	long long get_num();
	// 获取符号位
	long long get_sign();
	// 获取数字位
	long long get_x();
	// 获取阶码位
	long long get_e();

	// << 重载
	friend ostream& operator<<(ostream& os, Int num);
	// >> 重载
	friend ostream& operator<<(ostream& os, Int num);
	// + 重载
	Int operator+(Int& num);
	// - 重载
	Int operator-(Int& num);

};

/************************************* 浮点数类 ******************************************/
class Float : public Num
{
public:
	Float();
	Float(double num);
	Float(double num, CodeType type);
	~Float();
	// 原码一位乘法
	static Float multiply_true_code(Float a, Float b);
	// 补码一位乘法
	static Float multiply_complement_code(Float a, Float b);
private:
	// 浮点数
	u_float num;
	
public:
	// 转原码
	void convert_to_true_code();
	// 转反码
	void convert_to_inverse_code();
	// 转补码
	void convert_to_complement_code();
	// 转浮点数
	Float* convert_to_float();
	// 转整数
	Int* convert_to_int();
	// 打印数字
	void print_code_binary();
	// 十进制打印数字
	void print_num();
	// 输出数字
	string get_string();

	// 获取整个数
	long long get_num();
	// 获取符号位
	long long get_sign();
	// 获取数字位
	long long get_x();
	// 获取阶码位
	long long get_e();

	// 友元输出流重载
	friend ostream& operator<<(ostream& os, Float num);
};


