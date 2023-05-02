#include "queue.h"  
#include<stdio.h>
#include<stdlib.h>

int main(void) {
	Queue *queue = (Queue*)malloc(sizeof(Queue));
	double value;
	CreateQueue(queue, 5);
	puts("Enqueue 5 items ...");
	
	for (int x = 0; x < 5; x++)
		Enqueue(queue, x);
	DisplayQueue(queue);
	
	puts( "Now attempting to enqueue 5 ...");
	Enqueue(queue, 5);
	DisplayQueue(queue);
	
	Dequeue(queue, &value);
	printf("Retrieved element = %f\n", value);
	
	// DisplayQueue(queue);

	while(!IsEmpty(queue))
		Dequeue(queue, &value);
	DisplayQueue(queue);
	
	puts( "Now attempting to enqueue 7 ...");
	Enqueue(queue, 7);
	DisplayQueue(queue);
	
	DestroyQueue(&queue);
	DisplayQueue(queue);
}
