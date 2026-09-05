#include <stdio.h>
#include <malloc.h>
#include "queue.h"


void initQueue(Queue* q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(Queue* q)
{
    return (q->size == 0);
}

int isFull(Queue* q)
{
    return (q->size == MAX_SIZE);
}

int enqueue(Queue* q, int value)
{
    if (isFull(q))
    {
        printf("queue full\n");
        return 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    q->size++;
    return 1;
}

int dequeue(Queue* q, int* removeValue)
{
    if (isEmpty(q))
    {
        printf("queue empty\n");
        return 0;
    }
    *removeValue = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return 1;
}

int peek(Queue* q, int* frontValue)
{
    if (isEmpty(q))
    {
        printf("queue empty\n");
        return 0;
    }
    return *frontValue = q->data[q->front];
}

void reverseQueue(Queue* q, int k)
{
    int* arr = malloc(sizeof(int) * sizeof(q->size));
    int size = q->size;
    int remove;
    for (size_t i = 0; i < size; i++)
    {
        dequeue(q, &remove);
        arr[i] = remove;
    }

    int middle = k/2;
    int temp;
    for (size_t i = 0; i < middle; i++)
    {
        temp = arr[i];
        arr[i] = arr[k-i-1];
        arr[k-i-1] = temp;
    }

    for (size_t i = 0; i < size; i++)
    {
        enqueue(q, arr[i]);
    }
    free(arr);
}

void displayQueue(Queue* q)
{
    if (isEmpty(q))
    {
        printf("queue empty\n");
        return;
    }
    int index = q->front;
    for (int i = 0; i < q->size ; i++)
    {
        printf("%d ",q->data[index]);
        index = (index + 1) % MAX_SIZE;
    }
    printf("\n");
}