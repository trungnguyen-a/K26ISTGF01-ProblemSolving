#include <stdio.h>
#include "hashtable.h"


int main()
{
    int arr[4] = {2, 7, 11 ,15};
    Hashtable* ht = ht_create(5);
    for (size_t i = 0; i < 4; i++)
    {
        ht_put(ht, arr[i]);
    }
    print_table(ht);

    printf("elements sum = 9: ");
    for (size_t i = 0; i < 4; i++)
    {
        if (ht_contain(ht, 9-arr[i]))
        {
            printf("%d ", ht_get(ht, 9-arr[i]));
        }
    }

    printf("\n");
    ht_destroy(ht);
}