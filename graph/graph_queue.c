#include"graph_queue.h"
#include<stdio.h>
#include<stdlib.h>

G_Queue G_InitQueue() {
    G_Queue queue = (G_Queue) malloc (sizeof(struct G_Queue));
    if(queue == NULL) {
        printf("failed to create G_Queue!\n");
        exit(1);
    }
    queue->array = (int*) malloc (sizeof(int) * MAX_EDGE_NUMS);
    if(queue->array == NULL) {
        printf("failed to allocte memeory for queue!\n");
        exit(1);
    }
    queue->front = 0;
    queue->rear = 0;
}

void G_EnQueue(G_Queue q, const int data) {
    if(G_IsFullQueue(q)) {
        printf("G_Queue is full!\n");
        exit(1);
    }
    q->array[q->rear] = data;
    q->rear = (q->rear + 1) % MAX_EDGE_NUMS;
}
    
int G_DeQueue(G_Queue q) {
    if(G_IsEmptyQueue(q)) {
        printf("G_Queue is empty!\n");
        exit(1);
    }
    int tmp = q->array[q->front];
    q->front = (q->front + 1) % MAX_EDGE_NUMS;
    return tmp;
}
void G_MakeEmptyQueue(G_Queue q) {
    q->front = 0;
    q->rear = 0;
}
void G_DestoryQueue(G_Queue q) {
    free(q->array);
    free(q);
}

bool G_IsEmptyQueue(const G_Queue q) {
    return q->front == q->rear;
}

bool G_IsFullQueue(const G_Queue q) {
    return q->front == (q->rear + 1) % MAX_EDGE_NUMS;
}
