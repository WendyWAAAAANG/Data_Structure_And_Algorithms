#include "queue.h"
#include <stdio.h>

bool CreateQueue(Queue *queue, int size)
{
    if (size < 0)
        return false;
    queue->values = (double *)malloc(sizeof(double) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->maxSize = size;
    return true;
}
bool IsEmpty(Queue *queue)
{
    if (queue == NULL || queue->front == -1 && queue->rear == -1)
    {
        return true;
    }
    return false;
}
bool IsFull(Queue *queue)
{
    if (queue->front == 0 && queue->rear == queue->maxSize - 1 ||
        queue->front - 1 == queue->rear)
        return true;
    return false;
}
bool Enqueue(Queue *queue, double x)
{
    if (IsFull(queue))
        return false;
    if (IsEmpty(queue))
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->maxSize;
    }
    queue->values[queue->rear] = x;
    return true;
}
bool Dequeue(Queue *queue, double *x)
{
    if (IsEmpty(queue))
    {
        return false;
    }
    *x = queue->values[queue->front];
    if (queue->rear == queue->front)
    {
        queue->rear = -1;
        queue->front = -1;
        return true;
    }
    if (queue->front == queue->maxSize - 1)
    {
        queue->front = 0;
    }
    else
    {
        queue->front ++;
    }
    return true;
}
void DisplayQueue(Queue *queue)
{
    if (!IsEmpty(queue))
    {
        int front = queue->front, rear = queue->rear;
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
                printf("%f ", queue->values[i]);
        }
        else
        {
            for (int i = front; i < queue->maxSize; i++)
                printf("%f ", queue->values[i]);

            for (int i = 0; i <= rear; i++)
                printf("%f ", queue->values[i]);
        }
        printf("\n");
    }
}
void DestroyQueue(Queue **queue)
{
    if (*queue != NULL)
    {
        if ((*queue)->values != NULL)
            free((*queue)->values);
        free(*queue);
        *queue = NULL;
    }
}