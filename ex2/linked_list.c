#include <stdio.h>
#include <malloc.h>
#include "linked_list.h"


LinkedList* createList()
{
    LinkedList* newList = malloc(sizeof(LinkedList));
    newList->head = NULL;
    newList->tail = NULL;
    newList->size = 0;
    return newList;
}

Node* createNode(int value)
{
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void addLast(LinkedList* list, int value)
{
    Node* node = createNode(value);
    if (isEmpty(list))
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void addFirst(LinkedList* list, int value)
{
    Node* node = createNode(value);
    if (isEmpty(list))
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}

int indexOf(LinkedList* list, int value)
{
    int index = 0;
    Node* node = list->head;
    while (node != NULL)
    {
        if (node->value == value)
        {
            return index;
        }
        index++;
        node = node->next;   
    }
    return -1;
}

int contains(LinkedList* list, int value)
{
    if(indexOf(list, value) == -1)
    {
        return 0;
    }
    return 1;
}

int isEmpty(LinkedList* list)
{
    return (list->size == 0);
}

void removeFirst(LinkedList* list)
{
    if (isEmpty(list))
    {
        return;
    }
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

void removeLast(LinkedList* list)
{
    if (isEmpty(list))
    {
        return;
    }
    Node* temp = list->tail;
    Node* node = list->head;
    while (node != NULL)
    {
        if (node->next->value == list->tail->value)
        {
            node->next = NULL;
            break;
        }
        node = node->next;
    }
    list->tail = node;
    free(temp);
    list->size--;
}

int *toArray(LinkedList* list)
{
    int* arr = malloc(sizeof(list));
    int i = 0;
    while (list->head != NULL)
    {
        arr[i++] = list->head->value;
        list->head = list->head->next;
    }
    return arr;
}

void reverseLinkedList(LinkedList* list)
{
    Node* prev = NULL;
    Node* current = list->head;
    Node* next = NULL;
    list->tail = list->head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}

void printList(LinkedList* list)
{
    Node* node = list->head;
    printf("List size: %d\n", list->size);
    printf("head value: %d\n", list->head->value);
    printf("tail value: %d\n", list->tail->value);
    while (node != NULL)
    {
        printf("%d - ", node->value);
        node = node->next;
    }
    printf("NULL");
    printf("\n");
}
