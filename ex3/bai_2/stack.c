#include<stdio.h>
#include "stack.h"

void init(Stack* s)
{
    s->top = -1;
}

int isEmpty(const Stack* s)
{
    return (s->top == -1);
}

int isFull(const Stack* s)
{
    return (s->top == MAX_SIZE-1);
}

static void sorted(Stack* s)
{
    if (s->top == 0)
    {
        return;
    }

    for (int i = 0; i < s->top; i++)
    {
        for (int k = 0; k < s->top; k++)
        {
            if (s->sortedData[k] < s->sortedData[k+1])
            {
                int temp = s->sortedData[k];
                s->sortedData[k] = s->sortedData[k+1];
                s->sortedData[k+1] = temp;
            }
        }
    }
}

int min(const Stack* s)
{
    return s->sortedData[s->top];
}

void push(Stack* s, int value)
{
    if (isFull(s))
    {
        printf("Stack is full");
        return;
    }
    s->data[++(s->top)] = value;
    s->sortedData[s->top] = value;
    sorted(s);
}

int pop(Stack* s)
{
    if (isEmpty(s))
    {
        printf("Stack empty\n");
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
        printf("Stack empty\n");
        return;
    }

    printf("Print Stack: ");
    for (size_t i = 0; i <= s->top; i++)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}