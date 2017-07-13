#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

struct StackNode{
	DataType data;
	StackNode *next;
};

int IsEmptyStack(const Stack stack) {
	return stack->next == NULL;
}

Stack CreateStack(void) {
	Stack S = (Stack) malloc (sizeof(StackNode));
	if(!S) {
		printf("memory is full, create stack failed!\n");
		return NULL;
	}
	S->next = NULL;
	return S;
}

void Push(Stack stack, DataType data) {
	if(stack == NULL) {
		printf("must create a stack first!\n");
		return ;
	}
	StackNode* node = (StackNode*) malloc (sizeof(StackNode));
    if(node == NULL) {
        printf("failed to create StackNode, memeory is full!\n");
        exit(1);
    }
	node->data = data;
	node->next = stack->next;
	stack->next = node;
}

DataType Pop(Stack stack) {
	if(stack == NULL) {
		printf("must create stack first!\n");
		exit(1);
	}
	if(IsEmptyStack(stack)) {
		printf("stack is empty! no data to pop!\n");
		exit(1);
	}
	StackNode *tmp = stack->next;
	DataType data = tmp->data;
	stack->next = tmp->next;
	free(tmp);
	return data;
}

void MakeEmptyStack(Stack stack) {
	if(stack == NULL) {
		printf("the stack doesn't exist! create one first!\n");
		return ;
	}
	if(IsEmptyStack(stack)) {
		printf("stack is already empty!\n");
		return ;
	}
	while(!IsEmptyStack(stack)) {
		Pop(stack);
	}
}

void DestoryStack(Stack stack) {
	if(stack == NULL) {
		printf("the stack doesn't exist!\n");
		return ;
	}

	free(stack);
}


