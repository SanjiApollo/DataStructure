#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include"priority_queue.h"

#define LENGTH 10

void GetRandNums(int *A, int length);

int
main() {	
	PriorityQueue q = PQ_Init(LENGTH);

	int nums[LENGTH];

	GetRandNums(nums, LENGTH);
	
	for(int i = 0; i < LENGTH; ++i) {
		printf("%4d|", i + 1);
	}
	printf("\n");
	for(int i = 0; i < 80; ++i) {
		printf("-");
	}
	printf("\n");
	for(int i = 0; i < LENGTH; ++i) {
		PQ_Insert(q, nums[i]);
		PQ_Visit(q);
	}
	printf("\n");
	for(int i = 0; i < 80; ++i) {
		printf("-");
	}
	printf("\n");
	for(int i = 0; i < LENGTH; ++i) {
		printf("%4d|", i + 1);
	}
	printf("\n");
	for(int i = 0; i < 80; ++i) {
		printf("-");
	}
	printf("\n");
	for(int i = 0; i < LENGTH; ++i) {
		PQ_Visit(q);
		PQ_DeleteMin(q);
	}
	printf("\n");
	PQ_Destory(q);
}

void GetRandNums(int *A, int length) {
	srand((unsigned)time(NULL));
	int i, j;
	for(i = 0; i < length; ++i) {
		int tmp = rand() % 50 + 1;
		for(j = 0; j < i; ++j) {
			if(tmp == A[j]) break;
		}
		if(j == i) A[i] = tmp;
		else i--;
	}
}
