#include <stdio.h>
#include "queue.h"


int main()
{
    Queue q;

    queueInit(&q);
    printf("size %d\n", size(&q));

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    printf("size %d\n", size(&q));
    display(&q);
    
    int remove;
    dequeue(&q, &remove);
    printf("remove %d\n", remove);
    printf("size %d\n", size(&q));
    
    int peekValue;
    peek(&q, &peekValue);
    printf("peek %d\n", peekValue);
    
    dequeue(&q, &remove);
    printf("size %d\n", size(&q));
    dequeue(&q, &remove);
    printf("size %d\n", size(&q));
    dequeue(&q, &remove);
    printf("size %d\n", size(&q));
    display(&q);
    
    enqueue(&q, 40);
    display(&q);
}