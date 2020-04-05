#pragma once
#include "nodeRBT.h"


class RedBlackTree
{
private:
	NodeRBT* root;
	NodeRBT* nil;

public:
	void leftRotate(NodeRBT* x);
};