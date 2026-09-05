#include <stdio.h>
#include "queue.h"


int main()
{
    Stack s;
    initStack(&s);
    push(&s, 50);
    push(&s, 60);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    int remove;
    pop(&s, &remove);
    printf("pop %d\n", remove);
    display(&s);

    push(&s, 510);
    push(&s, 1000);
    display(&s);

    pop(&s, &remove);
    printf("pop %d\n", remove);
    display(&s);
}