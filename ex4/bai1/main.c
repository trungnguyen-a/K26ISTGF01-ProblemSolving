#include <stdio.h>
#include "queue.h"

int main()
{
    Queue q;

    initQueue(&q);
    for (int i = 5; i < 50; i+=5)
    {
        enqueue(&q, i);
    }

    printf("%d \n", q.size);
    displayQueue(&q);
    
    for (size_t i = 0; i < 3; i++)
    {
        int removed_value;
        dequeue(&q, &removed_value);
        printf("remove %d\n", removed_value);
    }
    int peek_value;
    peek(&q, &peek_value);
    printf("peek %d\n", peek_value);
    printf("%d \n", q.size);
    displayQueue(&q);
    
    reverseQueue(&q, 4);
    displayQueue(&q);
    reverseQueue(&q, 3);
    displayQueue(&q);
}