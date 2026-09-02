#include <stdio.h>
#include "stack.h"

void init(Stack* s)
{
    s->top = -1;
}

int isEmpty(const Stack *s)
{
    return (s->top == -1);
}

int isFull(const Stack *s)
{
    return (s->top == MAX_SIZE-1);
}

void push(Stack* s, int value)
{
    if (isFull(s))
    {
        return;
    }
    s->data[++(s->top)] = value;
}

int pop(Stack* s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    return s->data[(s->top)--];
}

int peek(const Stack* s)
{
    return s->data[s->top];
}

void display(const Stack* s)
{
    if (isEmpty(s))
    {
        printf("Stack empty");
        return;
    }
    
    printf("Print Stack: ");
    for (size_t i = 0; i <= s->top; i++)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

void stackArrayInit(StackArray* sArray)
{
    for (int i = 0; i < MAX_STACK; i++)
    {
        sArray->stacks[i].top = -1;
    }
}

int isEmpty1(const StackArray* sArray)
{
    return (sArray->stacks[0].top == -1);
}

int isEmpty2(const StackArray* sArray)
{
    return (sArray->stacks[1].top == -1);
}

int isFull1(const StackArray* sArray)
{
    return (sArray->stacks[0].top == MAX_SIZE-1);
}

int isFull2(const StackArray* sArray)
{
    return (sArray->stacks[1].top == MAX_SIZE-1);
}

void push1(StackArray* sArray, int value)
{
    if (isFull1(sArray))
    {
        printf("Stack 1 is full");
        return;
    }
    sArray->stacks[0].data[++(sArray->stacks[0].top)] = value;    
}

void push2(StackArray* sArray, int value)
{
    if (isFull2(sArray))
    {
        printf("Stack 2 is full");
        return;
    }
    sArray->stacks[1].data[++(sArray->stacks[1].top)] = value;    
}

int pop1(StackArray* sArray)
{
    if (isEmpty1(sArray))
    {
        printf("Stack 1 is empty");
        return -1;
    }
    return sArray->stacks[0].data[(sArray->stacks[0].top)--];
}

int pop2(StackArray* sArray)
{
    if (isEmpty2(sArray))
    {
        printf("Stack 2 is empty");
        return -1;
    }
    return sArray->stacks[1].data[(sArray->stacks[1].top)--];
}

void stackArrDisplay(StackArray* sArray)
{
    if (isEmpty1(sArray))
    {
        printf("Stack 1 empty\n");
    }
    else
    {
        printf("Stack 1:\n");
        for (int k = 0; k <= sArray->stacks[0].top; k++)
        {
            printf("%d ", sArray->stacks[0].data[k]);
        }
        printf("\n");
    }
    
    if (isEmpty2(sArray))
    {
        printf("Stack 2 empty\n");
    }
    else
    {
        printf("Stack 2:\n");
        for (int k = 0; k <= sArray->stacks[1].top; k++)
        {
            printf("%d ", sArray->stacks[1].data[k]);
        }
        printf("\n");
    }
}