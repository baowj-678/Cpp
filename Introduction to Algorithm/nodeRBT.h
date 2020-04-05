#pragma once
#include "nodeBST.h"
#define		RED		0
#define		BLACK	1
typedef int Color;


class NodeRBT :public NodeBST
{
private:
	Color color;

public:
	Color getColor();
	void setColor(Color color);
	NodeRBT* getRight();
	NodeRBT* getLeft();
	NodeRBT* getParent();

};