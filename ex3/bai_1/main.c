#include <stdio.h>
#include "stack.h"

int main()
{
    Stack s1, s2;
    StackArray arr;
    stackArrayInit(&arr);
    push1(&arr, 2);    
    push1(&arr, 5);    
    push1(&arr, 4);    
    push2(&arr, 7);    
    push2(&arr, 23);    
    stackArrDisplay(&arr);

    int remove = pop1(&arr);
    printf("pop %d\n", remove);
    remove = pop1(&arr);
    printf("pop %d\n", remove);
    stackArrDisplay(&arr);
    
    remove = pop1(&arr);
    printf("pop %d\n", remove);
    stackArrDisplay(&arr);
}