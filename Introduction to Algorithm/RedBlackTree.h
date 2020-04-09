#pragma once
#include "nodeRBT.h"


class RedBlackTree
{
private:
	NodeRBT* root;
	NodeRBT* nil;

public:
	void leftRotate(NodeRBT* x);
	void rightRotate(NodeRBT* x);
	void insert(NodeRBT* z);
	void insertFixup(NodeRBT* z);
	NodeRBT* deletee(NodeRBT* z);
	void deleteFixup(NodeRBT* z);
	NodeRBT* successor(NodeRBT* root);
	NodeRBT* getMin(NodeRBT* root);
};