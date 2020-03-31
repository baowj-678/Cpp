#pragma once
#include "QuickUnionUF.h"

class QuickUnionUFWeighted : QuickUnionUF
{
private:
	int* sz;
public:
	QuickUnionUFWeighted(int n) :QuickUnionUF(n)
	{
		this->sz = new int[n];
		for (int i(0); i < n; i++)
			this->sz[i] = 1;
	}
	~QuickUnionUFWeighted();
	void unionn(int p, int q);

};