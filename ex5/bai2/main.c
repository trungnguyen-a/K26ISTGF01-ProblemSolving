#include <stdio.h>
#include <malloc.h>
#include "hashtable.h"

int main()
{
    Hashtable* ht = ht_create(10);
    int arr[7] = {1, 7, 5, 9, 2, 12, 3};
    for (size_t i = 0; i < 7; i++)
    {
        ht_put(ht, arr[i]);
    }
    printTable(ht);

    int count = 0;
    for (size_t i = 0; i < 7; i++)
    {
        if (contain_value(ht, arr[i] + 2))
        {
            count++;
        }
    }
    printf("count: %d\n",count);
    ht_destroy(ht);
}