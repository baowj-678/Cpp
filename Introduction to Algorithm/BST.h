#pragma once
#include "nodeBST.h"

class BST
{
private:
	NodeBST* root;

public:
	BST();
	~BST();
	void put(Key key, Value val);
	Value get(Key key);
	void deletee(Key key);
};