#include "RedBlackTree.h"

void RedBlackTree::leftRotate(NodeRBT* x)
{
	NodeRBT* y = x->getRight();
	if (y == this->nil)
		return;
	x->setRight(y->getLeft());
	if (y->getLeft() != this->nil)
	{
		y->getLeft()->setParent(x);
	}
	y->setParent(x->getParent());
	if (x->getParent() == this->nil)
	{
		this->root = y;
	}
	else if (x == x->getParent()->getLeft())
		x->getParent()->setLeft(y);
	else
		x->getParent()->setRight(y);
	y->setLeft(x);
	x->setParent(y);
}