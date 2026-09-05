#include <stdio.h>
#include "queue.h"

static void enqueue(Queue* q, int value)
{
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    q->size++;
}

static int dequeue(Queue* q)
{
    int tmp = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return tmp;
}

int isFull(Stack* s)
{
    return (s->size == MAX_SIZE);
}

int isEmpty(Stack* s)
{
    return (s->size == 0);
}

void initStack(Stack* s)
{
    for (size_t i = 0; i < 2; i++)
    {
        s->q[i].front = 0;
        s->q[i].rear = -1;
        s->q[i].size = 0;
    }
    s->size = 0;
    s->currentQueue = 0;
}

void push(Stack* s, int value)
{
    if (isFull(s))
    {
        printf("Stack full\n");
        return;
    }
    switch (s->currentQueue)
    {
        case 0:
            enqueue(&s->q[0], value);
            break;
        case 1:
            enqueue(&s->q[1], value);
            break;
    }
    s->size++;
}

void pop(Stack* s, int* remove_value)
{
    if (isEmpty(s))
    {
        printf("Stack empty\n");
        return;
    }
    switch (s->currentQueue)
    {
        case 0:
            popValue(s, 0, remove_value);
            s->currentQueue = 1;
            break;
        case 1:
            popValue(s, 1, remove_value);
            s->currentQueue = 0;
            break;
    }
    s->size--;
}

void popValue(Stack* s, int q, int* remove_value)
{
    int iterateTimes = s->q[q].size - 1;
    int n = (q == 0)? 1 : 0;
    for (size_t i = 0; i < iterateTimes; i++)
    {
        int tmp = dequeue(&s->q[q]);
        enqueue(&s->q[n], tmp);
    }
    *remove_value = dequeue(&s->q[q]);
}

void display(Stack* s)
{
    if (isEmpty(s))
    {
        printf("stack empty");
        return;
    }
    int index;
    switch (s->currentQueue)
    {
        case 0:
            printf("queue 0\n");
            printStack(s, 0);
            break;
        case 1:
            printf("queue 1\n");
            printStack(s, 1);
            break;
    }
}

void printStack(Stack* s, int q)
{
    int index = s->q[q].front;
    for (size_t i = 0; i < s->q[q].size; i++)
    {
        printf("%d ", s->q[q].data[index]);
        index = (index + 1) % MAX_SIZE;
    }
    printf("\n");
}