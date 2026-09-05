#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

typedef struct Queue
{
    Node* head;
    Node* tail;
    int size;
} Queue;

void queueInit(Queue* q);
Node* createNode(int value);
int enqueue(Queue* q, int value);
int dequeue(Queue* q, int* removed_value);
int peek(Queue* q, int* front_value);
int size(Queue* q);
int isEmpty(Queue* q);
void display(Queue* q);

#endif