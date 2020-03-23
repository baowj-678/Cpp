#ifndef _SPLAY_NODE_
#define _SPLAY_NODE_

struct SplayNode;
typedef struct SplayNode* PtrToSplayNode;
typedef struct SplayNode* SplayTree;
typedef int ElementType;
typedef struct SplayNode* Position;


SplayTree Initialize(void);
SplayTree MakeEmpty(SplayTree T);
SplayTree DeleteTree(SplayTree T);
SplayTree Find(ElementType X, SplayTree T);
SplayTree FindMin(SplayTree T);
SplayTree FindMax(SplayTree T);
//Important!!!
SplayTree Insert(ElementType X, SplayTree T);
SplayTree Remove(ElementType X, SplayTree T);
ElementType Retrieve(SplayTree T);
//Important!!!
SplayTree Splay(ElementType Item, Position X);
SplayTree SingleRotateWithLeft(Position X);
SplayTree SingleRotateWithRight(Position X);

#endif // !_SPLAY_NODE_

