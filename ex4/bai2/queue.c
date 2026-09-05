#include <stdio.h>
#include <malloc.h>
#include "queue.h"

void queueInit(Queue* q)
{
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

Node* createNode(int value)
{
    Node* node = malloc(sizeof(Node));
    if (!node)
    {
        printf("node allocate failed\n");
        return NULL;
    }
    node->value = value;
    node->next = NULL;
    return node;
}

int enqueue(Queue* q, int value)
{
    Node* temp = createNode(value);
    if (isEmpty(q))
    {
        q->head = temp;
        q->tail = temp;
        q->size++;
        return 1;
    }
    q->tail->next = temp;
    q->tail = temp;
    q->size++;
    return 1;
}

int dequeue(Queue* q, int* removed_value)
{
    if (isEmpty(q))
    {
        printf("queue empty\n");
        return 0;
    }
    Node* node = q->head;
    *removed_value = q->head->value;
    q->head = q->head->next; 
    q->size--;
    free(node);
    return 1;
}

int peek(Queue* q, int* peek_value)
{
    if (isEmpty(q))
    {
        printf("queue empty\n");
        return 0;
    }
    *peek_value = q->head->value;
    return 1;
}

int size(Queue* q)
{
    return q->size;
}

int isEmpty(Queue* q)
{
    return (q->size == 0); 
}

void display(Queue* q)
{
    if (isEmpty(q))
    {
        printf("queue empty\n");
        return;
    }
    
    Node* node = q->head;
    printf("Print Queue:\n");
    while (node != NULL)
    {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}