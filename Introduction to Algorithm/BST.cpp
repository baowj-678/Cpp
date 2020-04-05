#include "BST.h"
#include <iostream>

BST::BST()
{
	this->root = NULL;
}

void BST::insert(NodeBST* T, NodeBST* z)
{
	NodeBST* y = NULL;
	NodeBST* x = this->root;
	while (x != NULL)
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
	if (z->getKey() < y->getKey())
	{
		y->setLeft(z);
	}
	else
	{
		y->setRight(z);
	}

	z->setParent(y);
	if (y == NULL)
	{
		this->root = z;
		z->setParent(NULL);
	}
}

void BST::insert(Key key, Value val)
{
	NodeBST* z = new NodeBST(key, val);
	this->insert(this->root, z);
}

NodeBST* BST::search(NodeBST* root, Key key)
{
	if (root == NULL || key == root->getKey())
		return root;
	if (key < root->getKey())
		return this->search(root->getLeft(), key);
	else
		return this->search(root->getRight(), key);
}


void BST::InorderTreeWalk(NodeBST* root)
{
	if (root == NULL)
		return;
	this->InorderTreeWalk(root->getLeft());
	std::cout << root->getKey() << " ";
	this->InorderTreeWalk(root->getRight());
}

void BST::PreorderTreeWalk(NodeBST* root)
{
	if (root == NULL)
		return;
	std::cout << root->getKey() << " ";
	this->PreorderTreeWalk(root->getLeft());
	this->PreorderTreeWalk(root->getRight());
}
void BST::PostorderTreeWalk(NodeBST* root)
{
	if (root == NULL)
		return;
	this->PostorderTreeWalk(root->getLeft());
	this->PostorderTreeWalk(root->getRight());
	std::cout << root->getKey() << " ";
}

NodeBST* BST::search(Key key)
{
	NodeBST* x = this->root;
	while (x != NULL && root->getKey() != key)
	{
		if (key < root->getKey())
			x = root->getLeft();
		else
			x = root->getRight();
	}
	return x;
}

NodeBST* BST::getMin(NodeBST* root)
{
	if (root == NULL)
		return NULL;
	while (root->getLeft() != NULL)
		root = root->getLeft();
	return root;
}

NodeBST* BST::getMax(NodeBST* root)
{
	if (root == NULL)
		return NULL;
	while (root->getRight() != NULL)
		root = root->getRight();
	return root;
}

NodeBST* BST::successor(NodeBST* root)
{
	if (root == NULL)
		return NULL;
	if (root->getRight() != NULL)
		return this->getMin(root->getRight());
	NodeBST* p = root->getParent();
	while (p != NULL && root == p->getRight())
	{
		root = p;
		p = root->getParent();
	}
	return p;
}

NodeBST* BST::predecessor(NodeBST* root)
{
	if (root == NULL)
		return NULL;
	if (root->getLeft() != NULL)
		return this->getMax(root->getLeft());
	NodeBST* p = root->getParent();
	while (p != NULL && root == p->getLeft())
	{
		root = p;
		p = root->getParent();
	}
	return p;
}

void BST::deletee(Key key)
{
	NodeBST* z = this->search(key);
	this->deletee(this->root, z);
}

void BST::deletee(NodeBST* root, NodeBST* z)
{
	// the node to br deleteed
	NodeBST* y = NULL;
	// node y 's not NIL sons
	NodeBST* x = NULL;
	if (z->getLeft() == NULL || z->getRight() == NULL)
	{
		y = z;
	}
	else
	{
		y = this->successor(z);
	}

	if (y->getLeft() != NULL)
	{
		x = y->getLeft();
	}
	else
	{
		x = y->getRight();
	}

	if (x != NULL)
	{
		x->setParent(y->getParent());
	}
	if (y->getParent() == NULL)
		this->root = x;
	else if (y == y->getParent()->getLeft())
		y->getParent()->setLeft(x);
	else
		y->getParent()->setRight(x);

	if (y != z)
	{
		z->setKey(y->getKey());
		z->setValue(y->getValue());
	}
}