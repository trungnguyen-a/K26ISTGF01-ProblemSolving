#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

typedef struct LinkedList
{
    Node* head;
    Node* tail;
    int size;
} LinkedList;


LinkedList* createList();

Node* createNode(int value);

void addLast(LinkedList* list, int value);

void addFirst(LinkedList* list, int value);

int indexOf(LinkedList* list, int value);

int contains(LinkedList* list, int value);

int isEmpty(LinkedList* list);

void removeFirst(LinkedList* list);

void removeLast(LinkedList* list);

int* toArray(LinkedList* list);

void reverseLinkedList(LinkedList* list);

void printList(LinkedList* list);



#endif