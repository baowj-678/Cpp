#pragma once
#include "INT.h"

enum NumType
{
	int_ = 1,
	float_ = 2
};


/************************************* 数字超类 ******************************************/
class Num
{
public:
	Num();
	~Num();
	// 输出数字存储的二进制形式
	static void num_to_binary(void* p, int n);

protected:
	// 标识符
	NumType is_float;
private:
};


/************************************* 整数类 ******************************************/
class Int : Num
{
public:
	Int();
	~Int();

private:

};




/************************************* 浮点数类 ******************************************/
class Float : Num
{
public:
	Float();
	~Float();

private:

};


