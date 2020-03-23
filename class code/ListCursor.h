#ifndef _LIST_CURSOR_
#define _LIST_CURSOR_
typedef int ElementType;
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitializeCursorSpace(void);

List MakeEmpty(List L);
List CreateList(void);
bool IsEmpty(const List L);
bool Append(ElementType element, List L);
Position Find(ElementType element, List L);//get the position of element in L,if there isn't ,return 0;
void Delete(ElementType element, List L);//del element from List l;
ElementType First(List L);//get the first element of L,if it's empty return -1;
void Insert(ElementType element, List L, Position P);//Insert the element after P;
bool IsSpaceEmpty(void);
void DeleteList(List L);
void PrintList(List L);

#endif // !_LIST_CURSOR_
