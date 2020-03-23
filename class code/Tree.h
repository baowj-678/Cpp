#ifndef _TREE_H_
#define _TREE_H_

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;
typedef int ElementType;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
//ElementType Retrieve(Position P);

struct TreeNode
{
	int Element;
	SearchTree Left;
	SearchTree Right;
};
#endif // !_TREE_H_

