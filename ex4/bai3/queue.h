#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 100
#define MAX_QUEUE 2

typedef struct Queue
{
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

typedef struct Stack
{
    Queue q[MAX_QUEUE];
    int size;
    int currentQueue;
} Stack;

static void enqueue(Queue* q, int value);
static int dequeue(Queue* q);
static int queueEmpty(Queue* q);

int isFull(Stack* s);
int isEmpty(Stack* s);
void initStack(Stack* s);
void push(Stack* s, int value);
void pop(Stack* s, int* remove_value);
void popValue(Stack* s, int q, int* remove_value);
void display(Stack* s);
void printStack(Stack* s, int q);

#endif