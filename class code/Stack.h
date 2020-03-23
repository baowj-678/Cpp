#ifndef _STACK_H_
#define _STACK_H_
#include "Tree.h"

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;
//typedef int ElementType;
typedef SearchTree ElementType;

int IsEmpty(Stack S);
//³õÊ¼»¯¶ÑÕ»
Stack CreateStack(void);
//Ïú»Ù¶ÑÕ»
void DisposeStack(Stack S);
//Çå¿Õ¶ÑÕ»
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
#endif // !_STACK_H_


