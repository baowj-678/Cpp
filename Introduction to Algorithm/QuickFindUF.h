#pragma once
#ifndef _QUICK_FIND_UF_
#define _QUICK_FIND_UF_
#include <map>
#include <string>

class QuickFindUF
{
public:
	QuickFindUF(int n);
	~QuickFindUF();
	void inputMap();
	bool connected(int p, int q);
	bool connected(std::string p, std::string q);
	void unionn(int p, int q);
	void unionn(std::string p, std::string q);
private:
	int* id;
	int num;
	std::map<std::string, int> elementToid;
};




#endif // !_QUICK_FIND_UF_

