#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include"algorithm.h"

#define ARRAY_SIZE 10

void PrintArray(int *A, int n);
void PrintNums(int n);
void Seperator();
void GetRandNums(int *A, int length);

void main() {
    int *A = (int*) malloc (sizeof(int) * (ARRAY_SIZE + 1));
    if(A == NULL) {
        printf("failed to allocte memeory, A is NULL!\n");
        exit(1);
    }

    GetRandNums(A, ARRAY_SIZE);
    Seperator();
    printf("Original Array:\n");
    PrintNums(ARRAY_SIZE);
    PrintArray(A, ARRAY_SIZE);
    Seperator();
    printf("\n");
    

    // 简单选择排序
    // SimpleInsertSort(A, ARRAY_SIZE);
    // 希尔排序
    // ShellSort(A, ARRAY_SIZE);
    BiInsertSort(A, ARRAY_SIZE);

    Seperator();
    printf("After BiInsertSort:\n");
    PrintNums(ARRAY_SIZE);
    PrintArray(A, ARRAY_SIZE);
    Seperator();
    printf("\n");
    
    free(A);
}

void PrintArray(int *A, int n) {
    for(int i = 1; i <= n; ++i) {
        printf("%3d |", A[i]);
    }
    printf("\n");
}

void PrintNums(int n) {
    for(int i = 1; i <= n; ++i) {
        printf("%3d |", i);
    }
    printf("\n");
    Seperator();
}

void Seperator() {
	for(int i = 0; i < 60; ++i) {
		printf("-");
	}
    printf("\n");
}

// 可能会有死循环
void GetRandNums(int *A, int length) {
	srand((unsigned)time(NULL));
	int i, j;
	for(i = 1; i <= length; ++i) {
		int tmp = rand() % 50 + 1;
		/*for(j = 0; j < i; ++j) {
			if(tmp == A[j]) break;
		}
		if(j == i) A[i] = tmp;
		else i--;
        */
        A[i] = tmp;
	}
}
