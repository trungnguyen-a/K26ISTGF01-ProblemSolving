#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100
#define MAX_STACK 2

typedef struct Stack
{
    int data[MAX_SIZE];
    int top;
} Stack;

typedef struct StackArray
{
    Stack stacks[MAX_STACK];
} StackArray;

void init(Stack* s);
int isEmpty(const Stack *s);
int isFull(const Stack *s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(const Stack* s);
void display(const Stack* s);

void stackArrayInit(StackArray* sArray);
int isEmpty1(const StackArray* sArray);
int isEmpty2(const StackArray* sArray);
int isFull1(const StackArray* sArray);
int isFull2(const StackArray* sArray);
void push1(StackArray* sArray, int value);
void push2(StackArray* sArray, int value);
int pop1(StackArray* sArray);
int pop2(StackArray* sArray);
void stackArrDisplay(StackArray* sArray);

#endif