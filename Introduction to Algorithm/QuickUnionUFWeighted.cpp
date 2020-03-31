#include "QuickUnionUFWeighted.h"

void QuickUnionUFWeighted::unionn(int p, int q)
{
	p = this->root(p);
	q = this->root(q);
	if (p == q)
		return;
	if (this->sz[p] < this->sz[q])
	{
		this->id[p] = q;
		this->sz[q] += this->sz[p];
	}
	else
	{
		this->id[q] = p;
		this->sz[p] += this->sz[q];
	}
}

QuickUnionUFWeighted::~QuickUnionUFWeighted()
{
	delete[]this->sz;
}