#pragma once
#ifndef _QUICK_UNION_UF_
#define _QUICK_UNION_UF_
#include <string>
#include <map>


class QuickUnionUF
{
public:
	QuickUnionUF(int n);
	~QuickUnionUF();
	int root(int id);
	bool connect(int p, int q);
	bool connect(std::string p, std::string q);
	void unionn(int p, int q);
	void unionn(std::string p, std::string q);

private:
	int* id;
	std::map<std::string, int> nameToid;
	int num;
};





#endif // !_QUICK_UNION_UF_
