#pragma once
#include "nodeBST.h"

class BST
{
private:
	NodeBST* root;

public:
	BST();
	~BST();
	void insert(Key key, Value val);
	void insert(NodeBST* T, NodeBST* z);
	NodeBST* search(NodeBST* root, Key key);
	NodeBST* search(Key key);
	NodeBST* getMin(NodeBST* root);
	NodeBST* getMax(NodeBST* root);
	NodeBST* successor(NodeBST* root);
	NodeBST* predecessor(NodeBST* root);
	void deletee(Key key);
	void deletee(NodeBST* root, NodeBST* z);
	void InorderTreeWalk(NodeBST* root);
	void PreorderTreeWalk(NodeBST* root);
	void PostorderTreeWalk(NodeBST* root);
};