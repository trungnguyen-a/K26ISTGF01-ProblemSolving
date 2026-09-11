#include <stdio.h>
#include "hashtable.h"


int main()
{
    Hashtable* ht = ht_create(10);
    int arr[7] = {1, 2, 2, 3, 3, 3, 4};
    for (size_t i = 0; i < 7; i++)
    {
        ht_put(ht, arr[i]);
    }
    ht_printEntries(ht);
    printf("most repeat number: %d\n", ht_get_most_repeat_key(ht));
    ht_destroy(ht);
}