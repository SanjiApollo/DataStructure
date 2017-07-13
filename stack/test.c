#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"queue.h"

void main() {
	Queue queue = CreateQueue();

	EnQueue(queue, 'a');
	EnQueue(queue, 'b');
	EnQueue(queue, 'c');
	EnQueue(queue, 'd');
	EnQueue(queue, 'e');
	EnQueue(queue, 'f');
	EnQueue(queue, 'g');
	EnQueue(queue, 'h');
	EnQueue(queue, 'i');

	while(!IsEmptyQueue(queue)) {
		printf("%c ", DeQueue(queue));
	}

	printf("\n");
}
