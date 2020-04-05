#include "nodeBST.h"

NodeBST::NodeBST(Key key, Value val)
{
	this->key = key;
	this->val = val;
	this->right = nullptr;
	this->left = nullptr;
}

Key NodeBST::getKey()
{
	return this->key;
}

Value NodeBST::getValue()
{
	return this->val;
}

NodeBST* NodeBST::getLeft()
{
	return this->left;
}

NodeBST* NodeBST::getRight()
{
	return this->right;
}

void NodeBST::setRight(NodeBST* right)
{
	this->right = right;
}

void NodeBST::setLeft(NodeBST* left)
{
	this->left = left;
}

void NodeBST::setKey(Key key)
{
	this->key = key;
}

void NodeBST::setValue(Value value)
{
	this->val = value;
}

bool NodeBST::comparator(Key a, Key b)
{
	return a > b;
}

void NodeBST::setParent(NodeBST* parent)
{
	this->parent = parent;
}