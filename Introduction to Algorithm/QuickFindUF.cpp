#include "QuickFindUF.h"
#include <iostream>

QuickFindUF::QuickFindUF(int n)
{
	this->num = n;
	this->id = new int[n];
	for (int i(0); i < n; i++)
		this->id[i] = i;
}

QuickFindUF::~QuickFindUF()
{
	delete[] this->id;
}

void QuickFindUF::inputMap()
{
	std::string name;
	std::cout << "\nPlease input the element-name its id (from 0 to n - 1):\n";
	for (int i(0); i < this->num; i++)
	{
		std::cin >> name;
		this->elementToid[name] = i;
	}
	std::cout << "\nSuccessfully input!\n";
}


bool QuickFindUF::connected(int p, int q)
{
	return (this->id[p] == this->id[q]);
}

bool QuickFindUF::connected(std::string p, std::string q)
{
	return this->connected(this->elementToid[p], this->elementToid[q]);
}

void QuickFindUF::unionn(int p, int q)
{
	int pid = this->id[p];
	int qid = this->id[q];
	for (int i(0); i < this->num; i++)
	{
		if (this->id[i] == pid)
			this->id[i] = qid;
	}
}

void QuickFindUF::unionn(std::string p, std::string q)
{
	this->unionn(this->elementToid[p], this->elementToid[q]);
}