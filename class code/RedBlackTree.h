#ifndef _RED_BLACK_TREE_
#define _RED_BLACK_TREE_

struct RedBlackNode;
typedef int ElementType;
typedef struct RedBlackNode* PtrToRedBlackNode;
typedef struct RedBlackNode* RedBlackTree;
typedef struct RedBlackNode* Position;
typedef enum ColorType{Red, Black} ColorType;



RedBlackTree Initialize(void);
Position Rotate();
Position SingleRotateWithLeft(Position P);
Position SingleRotateWithRight(Position P);
RedBlackTree Insert(ElementType Item, RedBlackTree T);
//double child red
void HandleReorient(ElementType Item, RedBlackTree T);

#endif // !_RED_BLACK_TREE_

