#include <stdio.h>
#include "linked_list.h"

int main()
{
    LinkedList* linkedList = createList();

    addFirst(linkedList, 10);
    addLast(linkedList, 20);
    addLast(linkedList, 30);
    addLast(linkedList, 40);
    addLast(linkedList, 50);
    printList(linkedList);
    
    int index = indexOf(linkedList, 20);
    printf("index of 20: %d\n", index);
    
    reverseLinkedList(linkedList); 
    printList(linkedList);
    
    if (contains(linkedList, 80))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    
    removeFirst(linkedList);    
    printList(linkedList);
    
    removeLast(linkedList);
    printList(linkedList);

    int* arr = toArray(linkedList);
    printf("array: ");
    for (size_t i = 0; i < linkedList->size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}