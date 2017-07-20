#ifndef DS_GRAPH_QUEUE_H
#define DS_GRAPH_QUEUE_H

#include"graph.h"
#include<stdbool.h>

struct G_Queue;
typedef struct G_Queue *G_Queue;

struct G_Queue {
    int *array;
    int front;
    int rear;
};

G_Queue G_InitQueue();
void G_EnQueue(G_Queue q, const int data);
int G_DeQueue(G_Queue q);
void G_MakeEmptyQueue(G_Queue q);
void G_DestoryQueue(G_Queue q);
bool G_IsEmptyQueue(const G_Queue q);
bool G_IsFullQueue(const G_Queue q);

#endif
