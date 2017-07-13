#ifndef DS_LINK_STACK_H
#define DS_LINK_STACK_H
// a link stack

typedef char DataType;
struct StackNode;
typedef struct StackNode StackNode;
typedef struct StackNode *Stack;

// return an empty stack
Stack CreateStack(void);

// return 1 if the stack is empty, otherwise return 0
int IsEmptyStack(const Stack stack);

// push the data on the top
void Push(Stack stack, DataType data);

// return the top data
DataType Pop(Stack stack);

// make an empty stack
void MakeEmptyStack(Stack stack);

// destory the stack
void DestoryStack(Stack stack);

#endif
