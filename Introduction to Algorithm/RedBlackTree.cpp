#include "RedBlackTree.h"
#include <iostream>

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

void RedBlackTree::insert(NodeRBT* z)
{
	NodeRBT* y = this->nil;
	NodeRBT* x = this->root;
	while (x != this->nil)
	{
		y = x;
		if (z->getKey() < x->getKey())
		{
			x = x->getLeft();
		}
		else
		{
			x = x->getRight();
		}
	}
	z->setParent(y);
	if (y == this->nil)
	{
		this->root = z;
	}
	else if (z->getKey() < y->getKey())
	{
		y->setLeft(z);
	}
	else
	{
		y->setRight(z);
	}
	z->setLeft(this->nil);
	z->setRight(this->nil);
	z->setColor(RED);
	this->insertFixup(z);
}

void RedBlackTree::insertFixup(NodeRBT* z)
{
	NodeRBT* y = NULL;
	while (z->getParent()->getColor() == RED)
	{
		y = z->getParent()->getParent();
		if (z->getParent() == y->getLeft())
		{
			y = y->getRight();
			if (y->getColor() == RED)
			{
				z->getParent()->setColor(BLACK);
				y->setColor(BLACK);
				z->getParent()->getParent()->setColor(RED);
			}
			else if (z == z->getParent()->getRight())
			{
				z = z->getParent();
				this->leftRotate(z);
			}
			z->getParent()->setColor(BLACK);
			z->getParent()->getParent()->setColor(RED);
			this->rightRotate(z->getParent()->getParent());
		}
		else
		{

		}
	}
	this->root->setColor(BLACK);
}

void RedBlackTree::rightRotate(NodeRBT* x)
{
	NodeRBT* y = x->getLeft();
	if (y == this->nil)
		return;
	x->setLeft(y->getRight());
	if (y->getRight() != this->nil)
	{
		y->getRight()->setParent(x);
	}
	y->setParent(x->getParent());
	if (x->getParent() == this->nil)
	{
		this->root = y;
	}
	else if (x == x->getParent()->getRight())
		x->getParent()->setRight(y);
	else
		x->getParent()->setLeft(y);
	y->setRight(x);
	x->setParent(y);
	return;
}

NodeRBT* RedBlackTree::getMin(NodeRBT* root)
{
	if (root == NULL)
		return NULL;
	while (root->getLeft() != NULL)
		root = root->getLeft();
	return root;
}

NodeRBT* RedBlackTree::successor(NodeRBT* root)
{
	if (root == NULL)
		return NULL;
	if (root->getRight() != NULL)
		return this->getMin(root->getRight());
	NodeRBT* p = root->getParent();
	while (p != NULL && root == p->getRight())
	{
		root = p;
		p = root->getParent();
	}
	return p;
}

NodeRBT* RedBlackTree::deletee(NodeRBT* z)
{
	NodeRBT* y = NULL;
	NodeRBT* x = NULL;
	if (z->getLeft() == this->nil || z->getRight() == this->nil)
		y = z;
	else
		y = this->successor(z);
	if (y->getLeft() != this->nil)
		x = y->getLeft();
	else
		x = y->getRight();
	x->setParent(y->getParent());
	if (y->getParent() == this->nil)
		this->root = x;
	else if (y == y->getParent()->getLeft())
		y->getParent()->setLeft(x);
	else
		y->getParent()->setRight(x);

	if (y != x)
	{
		z->setKey(y->getKey());
		z->setValue(y->getValue());
	}

	if (y->getColor() == BLACK)
		this->deleteFixup(x);
	return y;
}
void RedBlackTree::deleteFixup(NodeRBT* z)
{

}