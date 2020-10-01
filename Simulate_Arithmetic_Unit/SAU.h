#pragma once

class SAU
{
public:
	SAU();
	~SAU();

private:
	// 原码转补码
	int convert_to_complement(int true_code);
	// 补码转原码
	int convert_to_truecode(int complement_code);
	// 原码转反码
	int convert_to_ones_complement(int true_code);
};

SAU::SAU()
{
}

SAU::~SAU()
{
}