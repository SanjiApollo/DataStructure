// a link queue

#ifndef DS_QUEUE_H
#define DS_QUEUE_H

struct BiTreeNode;

typedef struct BiTreeNode *DataType;

struct QueueNode;
typedef struct QueueNode QueueNode;
struct Queue;
typedef struct Queue *Queue;

Queue CreateQueue();

int IsEmptyQueue(Queue queue);

void EnQueue(Queue queue, DataType data);

DataType DeQueue(Queue queue);

void MakeEmptyQueue(Queue queue);

void DestoryQueue(Queue queue);

#endif
