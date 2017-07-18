#ifndef DS_GRAPH_INPUT_H
#define DS_GRAPH_INPUT_H

#include"graph.h"
#include<stdbool.h>

#define _G_INPUT_MAX_STACK_SIZE 1024

typedef struct _G_Input_Stack *_G_Input_Stack;

void MakeTheGraph(Graph g);

bool IsDigitalStr(char *digtStr, int length);
int Str2Int(char *digtStr, int length);

struct _G_Input_Stack {
    char array[_G_INPUT_MAX_STACK_SIZE];
    int top;
};

_G_Input_Stack _G_Input_InitStack();
bool _G_Input_IsEmptyStack(_G_Input_Stack s);
bool _G_Input_IsFullStack(_G_Input_Stack s);
void _G_Input_Push(_G_Input_Stack s, char ch);
char _G_Input_Pop(_G_Input_Stack s);
char _G_Input_GetTop(_G_Input_Stack s);
void _G_Input_MakeEmptyStack(_G_Input_Stack s);
void _G_Input_DestoryStack(_G_Input_Stack s);

#endif
