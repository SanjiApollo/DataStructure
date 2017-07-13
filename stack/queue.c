#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

struct QueueNode {
	DataType data;
	QueueNode *next;
};

struct Queue {
	QueueNode *front;
	QueueNode *rear;
};

Queue CreateQueue() {
	QueueNode *node = (QueueNode*) malloc (sizeof(QueueNode));
	if(node == NULL) {
		printf("memory if full!\n");
		exit(1);
	}
	Queue queue = (Queue) malloc (sizeof(struct Queue));
	queue->front = node;
	queue->rear = node;
	return queue;
}

int IsEmptyQueue(Queue queue) {
	return queue->front == queue->rear;
}

void EnQueue(Queue queue, DataType data) {
	if(queue == NULL) {
		printf("queue doesn't exist! create one first!");
		exit(1);
	}
	QueueNode *node = (QueueNode*) malloc (sizeof(QueueNode));
	if(node == NULL) {
		printf("failed to create QueueNode!\n");
		exit(1);
	}
	node->data = data;
	node->next = NULL;
	queue->rear->next = node;
	queue->rear = node;
}

DataType DeQueue(Queue queue) {
	if(queue == NULL) {
		printf("queue doesn't exist! create one first!");
		exit(1);
	}
	if(IsEmptyQueue(queue)) {
		printf("the queue is empty! no data exist!\n");
		exit(1);
	}
	QueueNode *tmp = queue->front->next;
	DataType data = tmp->data;
	queue->front->next = tmp->next;
	if(queue->rear == tmp) {
		queue->rear = queue->front;
	}
	free(tmp);
	return data;
}

void MakeEmptyQueue(Queue queue) {
	while(!IsEmptyQueue(queue)) {
		DeQueue(queue);
	}
}
