#pragma once
#include <string>
#include <map>


class QuickUnionUF
{
public:
	QuickUnionUF(int n);
	~QuickUnionUF();
	void inputMap();
	int root(int id);
	bool connect(int p, int q);
	bool connect(std::string p, std::string q);
	void unionn(int p, int q);
	void unionn(std::string p, std::string q);
	void pathCompression();

protected:
	int* id;
	std::map<std::string, int> nameToid;
	int num;
};

