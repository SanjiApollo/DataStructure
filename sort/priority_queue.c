#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"priority_queue.h"

#define MIN_DATA -1

PriorityQueue PQ_Init(int maxSize) {
	PriorityQueue queue;
	queue = (PriorityQueue) malloc (sizeof(struct HeapStruct));

	if(queue == NULL) {
		printf("failed to create PQ!\n");
		exit(1);
	}

	queue->array = (int*) malloc (sizeof(int) * (maxSize + 1));

	if(queue->array == NULL) {
		printf("failed to allocte memory for PQ!\n");
		exit(1);
	}

	queue->capacity = maxSize;
	queue->length = 0;
	queue->array[0] = MIN_DATA;

	return queue;
}

bool PQ_IsEmpty(PriorityQueue q) {
	return q->length == 0;
}

bool PQ_IsFull(PriorityQueue q) {
	return q->length == q->capacity;
}

// remain its capacity, but the queue is empty
void PQ_MakeEmpty(PriorityQueue q) {
	q->length = 0;
}

void PQ_Destory(PriorityQueue q) {
	free(q->array);
	free(q);
}

// 插入并建立堆序
void PQ_Insert(PriorityQueue q, int data) {
	if(PQ_IsFull(q)) {
		printf("priority queue is full!\n");
		exit(1);
	}
	int i = 0;
	for(i = ++q->length; q->array[i/2] > data; i /= 2) {
		q->array[i] = q->array[i/2];
	}
	q->array[i] = data;
}

// int PQ_DeleteMin(PriorityQueue q);

// int PQ_FindMin(PriorityQueue q);


void PQ_Visit(PriorityQueue q) {
	if(PQ_IsEmpty(q)) {
		printf("PQ is empty!\n");
		return ;
	}
	for(int i = 1; i <= q->length; ++i) {
	   printf("%4d", q->array[i]);
	}
	printf("\n");
}	

