#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

//function implementation.
bool CreateQueue(Queue *queue, int size){
    if(size <= 0){
        //which means the size is invalid.
        //we cannot create queue correspondly.
        return false;
    }
    //otherwise, we do the queue initialize.
    queue -> values = (double*)malloc(sizeof(double)*size);
    queue -> front = 0;
    queue -> rear = -1;
    queue -> counter = 0;
    queue -> maxSize = size - 1;
    return true;
}

bool IsEmpty(Queue* queue){
    //for safe, we check whether the queue is a null pointer.
    if(queue == NULL){
        //just return withous any operation.
        return false;
    }
    //to check whether the queue has element,
    //using counter.
    if(queue -> counter == 0){
        //which means queue no longer has elements.
        return true;
    }
    //otherwise the queue is not empty.
    return false;
}

bool IsFull(Queue* queue){
    //just return oppose result of IsEmpty.
    //return !IsEmpty(queue);
    if(queue -> counter == queue -> maxSize){
        //which means the queue is full.
        return true;
    }
    else{
        return false;
    }
}

bool Enqueue(Queue* queue, double x){
    //for safe, we check whether the queue is a null pointer.
    if(queue == NULL){
        //just return withous any operation.
        return false;
    }
    //we need to check whether the queue is full.
    //if so, the queue cannot add more elements.
    if(IsFull(queue)){
        //which means the queue is full.
        return false;
    }
    //otherwise, we put value into queue.
    queue -> rear = (++queue -> rear) % queue -> maxSize;
    queue -> values[queue -> rear] = x;
    queue -> counter++;
    return true;
}

bool Dequeue(Queue* queue, double* x){
    //for safe, we check whether the queue is a null pointer.
    if(queue == NULL){
        //just return withous any operation.
        return false;
    }
    //delete elements from queue,
    //we need to check whether the queue is already empty.
    if(IsEmpty(queue)){
        //which means the queue is empty.
        return false;
    }
    //otherwise, pass the value into x.
    *x = queue -> values[queue -> front];
    queue -> front = (++queue -> front) % queue -> maxSize;
    queue -> counter--;
    return true;
}

void DisplayQueue(Queue* queue){
    //for safe, we check whether the queue is a null pointer.
    if(queue == NULL){
        //just return withous any operation.
        return;
    }
    if(IsEmpty(queue)){
        //which means the queue donnot have any element to print.
        //just print a blank line.
        //printf("\n");
        return;
    }
    //otherwise, print the elements.
    for(int i = 0; i < queue -> counter; i++){
        printf("%f ", queue -> values[queue -> front]);
        queue -> front = (++queue -> front) % queue -> maxSize;
    }
    printf("\n");
    return;
}

void DestroyQueue(Queue** queue){
    Queue * cQueue = *queue;
    //just free the value memory of queue.
    free(cQueue -> values);
    free(cQueue);
    *queue = NULL;
    return;
}