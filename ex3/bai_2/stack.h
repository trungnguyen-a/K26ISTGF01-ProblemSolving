#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

typedef struct Stack
{
    int data[MAX_SIZE];
    int sortedData[MAX_SIZE];
    int top;
} Stack;

void init(Stack* s);
int isEmpty(const Stack* s);
int isFull(const Stack* s);
static void sorted(Stack* s);
int min(const Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(const Stack* s);
void display(const Stack* s);

#endif