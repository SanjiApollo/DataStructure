#ifndef DS_PRIORITY_QUEUE_H
#define DS_PRIORITY_QUEUE_H

#include<stdbool.h>


// 假设堆中的数据是整型int, 方便后续排序

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue PQ_Init(int maxSize);

bool PQ_IsEmpty(PriorityQueue q);

bool PQ_IsFull(PriorityQueue q);

void PQ_MakeEmpty(PriorityQueue q);

void PQ_Destory(PriorityQueue q);

void PQ_Insert(PriorityQueue q, int data);

int PQ_DeleteMin(PriorityQueue q);

int PQ_FindMin(PriorityQueue q);

void PQ_Visit(PriorityQueue q);

struct HeapStruct {
	int capacity;
	int length;
	int *array;
};

#endif
