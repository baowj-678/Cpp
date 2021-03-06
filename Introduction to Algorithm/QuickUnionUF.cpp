#include "QuickUnionUF.h"
#include <string>
#include <iostream>


QuickUnionUF::QuickUnionUF(int n)
{
	this->num = n;
	this->id = new int[n];
	for (int i(0); i < n; i++)
		this->id[i] = i;
}

QuickUnionUF::~QuickUnionUF()
{
	delete[]this->id;
}

int QuickUnionUF::root(int id)
{
	for (; id != this->id[id];)
		id = this->id[id];
	return id;
}

bool QuickUnionUF::connect(int p, int q)
{
	return this->root(p) == this->root(q);
}

bool QuickUnionUF::connect(std::string p, std::string q)
{
	return this->connect(this->nameToid[p], this->nameToid[q]);
}

void QuickUnionUF::unionn(int p, int q)
{
	p = this->root(p);
	q = this->root(q);
	this->id[p] = q;
}

void QuickUnionUF::unionn(std::string p, std::string q)
{
	this->unionn(this->nameToid[p], this->nameToid[q]);
}

void QuickUnionUF::inputMap()
{
	std::string name;
	std::cout << "\nPlease input the element-name its id (from 0 to n - 1):\n";
	for (int i(0); i < this->num; i++)
	{
		std::cin >> name;
		this->nameToid[name] = i;
	}
	std::cout << "\nSuccessfully input!\n";
}

void QuickUnionUF::pathCompression()
{
	for (int i(0); i < this->num; i++)
	{
		if (this->id[i] != i)
			this->id[i] = this->id[this->id[i]];
	}
}