#include "nodeRBT.h"


Color NodeRBT::getColor()
{
	return this->color;
}

void NodeRBT::setColor(Color color)
{
	this->color = color;
}

NodeRBT* NodeRBT::getRight()
{
	return (NodeRBT*)this->NodeBST::getRight();
}

NodeRBT* NodeRBT::getLeft()
{
	return (NodeRBT*)this->NodeBST::getLeft();
}

NodeRBT* NodeRBT::getParent()
{
	return (NodeRBT*)this->NodeBST::getParent();
}
