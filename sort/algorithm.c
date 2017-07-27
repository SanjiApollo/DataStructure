#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"algorithm.h"

void HeapSort(int *A, int n);


void QuickSort(int *A, int n);

void SimpleInsertSort(int *A, int n) {
    int i, j;
	for(i = 2; i <= n; ++i) {
		A[0] = A[i];
		j = i;
		while(A[j-1] > A[0] && j > 1) {
			A[j] = A[j-1];
            --j;
		}
		A[j] = A[0];
	}
}

void BiInsertSort(int *A, int n) {
    int i, j;
    int low, high, mid;
    low = 1; high = n;
    for(i = 2; i <= n; ++i) {
        low = 1; high = i - 1;
        A[0] = A[i];
        while(low <= high) {    // 要有等于，不然第一趟就不比较了
            mid = (low + high) / 2;
            if(A[mid] > A[0]) high = mid - 1;
            if(A[mid] <= A[0]) low = mid + 1;   // 考虑如果存在一连串的相同的关键字，为减少移动，应该定位在后面
        }
        j = i;
        while(j > low) {
            A[j] = A[j-1];
            --j;
        }
        A[low] = A[0];  // 最终插入在low的位置，可拿1,3; 1,0举例
    }
}
            

void ShellSort(int *A, int n) {
    int i, j, d;
    for(d = n/2; d != 0; d /= 2) {
        for(i = d; i <= n; ++i) {   // 这里跟一次性将一个等差序列排完一样的，只不过分开了
            A[0] = A[i];
            j = i;
            while(j-d > 0 && A[j-d] > A[0]) {
                A[j] = A[j-d];
                j -= d;
            }
            A[j] = A[0]; 
        }
    }
}
