#ifndef DS_GRAPH_INPUT_H
#define DS_GRAPH_INPUT_H

#include"graph.h"
#include<stdbool.h>

#define _G_INPUT_MAX_STACK_SIZE 1024

typedef struct _G_Input_Stack *_G_Input_Stack;

void MakeTheGraph(Graph g);

void GetEdgesWithWeight(char *edges, int *weights, int *edgenums);
bool IsDigitalStr(char *digtStr, int length);
int Str2Int(char *digtStr, int length);

#endif
