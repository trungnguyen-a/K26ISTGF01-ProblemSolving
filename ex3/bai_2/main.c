#include <stdio.h>
#include "stack.h"

int main()
{
    Stack s;
    init(&s);
    display(&s);
    push(&s, 10);
    push(&s, 40);
    push(&s, 30);
    push(&s, 1);
    display(&s);

    int m = min(&s);
    printf("min: %d\n", m);

    pop(&s);
    display(&s);
    m = min(&s);
    printf("min: %d\n", m);
}