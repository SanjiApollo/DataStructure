// a link queue

#ifndef DS_QUEUE_H
#define DS_QUEUE_H

typedef char DataType;

struct QueueNode;
typedef struct QueueNode QueueNode;
struct Queue;
typedef struct Queue *Queue;

Queue CreateQueue();

int IsEmptyQueue(Queue queue);

void EnQueue(Queue queue, DataType data);

DataType DeQueue(Queue queue);

void MakeEmptyQueue(Queue queue);

#endif
