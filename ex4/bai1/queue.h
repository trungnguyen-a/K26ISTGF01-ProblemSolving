#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 100

typedef struct Queue
{
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue* q);
int isEmpty(Queue* q);
int isFull(Queue* q);
int enqueue(Queue* q, int value);
int dequeue(Queue* q, int* removeValue);
int peek(Queue* q, int* frontValue);
void displayQueue(Queue* q);
void reverseQueue(Queue* q, int k);

#endif