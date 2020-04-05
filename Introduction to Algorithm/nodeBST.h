#pragma once

typedef int Key;
typedef int Value;

class NodeBST
{
private:
	Key key;
	Value val;
	NodeBST* left;
	NodeBST* right;
	NodeBST* parent;

public:
	//if a>b;return ture, else return false
	static bool comparator(Key a, Key b);
	NodeBST(Key key, Value val);
	Key getKey();
	Value getValue();
	NodeBST* getLeft();
	NodeBST* getRight();
	NodeBST* getParent();
	void setRight(NodeBST* right);
	void setLeft(NodeBST* left);
	void setKey(Key key);
	void setValue(Value value);
	void setParent(NodeBST* parent);
};